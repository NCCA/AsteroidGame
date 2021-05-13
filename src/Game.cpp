#include "Game.h"
#include "RenderGlobals.h"
#include <cstdlib>
#include <ngl/VAOPrimitives.h>
#include <ngl/Random.h>
#include <iostream>
#include <algorithm>
Game::Game(int _arenaSize) : m_arenaSize{_arenaSize}
{
  glClearColor(0.2f,0.2f,0.2f,1.0f);
  ngl::Random::setSeed();
  auto pos = ngl::Random::getRandomVec3() * 30;  
  pos.m_y=0.0f; // working in x/z plane
  m_ship.setPos(pos);
  RenderGlobals g(100);
  m_rocks.resize(5);
  m_text = std::make_unique<ngl::Text>("fonts/Impact_Label.ttf",24);
  m_text->setScreenSize(m_arenaSize,m_arenaSize);
}

void Game::draw() 
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  if(m_gameState == GameState::Playing)
  {
    m_ship.draw();
    for(auto r : m_rocks)
      r.draw();
    for(auto m : m_missile)
      m.draw();

    m_text->setColour(1.0f,1.0f,0.0f);
    m_text->renderText(10,370,fmt::format("Life {}",m_ship.getLife()));

    m_text->renderText(290,370,fmt::format("Score {}",m_score));
  }

  else if( m_gameState == GameState::MainMenu)
  {
    m_text->renderText(10,200,"Press Space to play");
  }
  else if( m_gameState == GameState::GameOver)
  {
    m_text->renderText(10,100,fmt::format("Game Over score was {}",m_score));
    m_text->renderText(10,200,"Press r to reset play");
  }

}

void Game::changeGameState(GameState _state)
{
  if(m_gameState == GameState::GameOver && _state == GameState::MainMenu)
  {
    m_gameState=_state;
    m_ship.resetShip();
  }
  else if( m_gameState == GameState::MainMenu)
  {
    m_gameState=_state;
  }

}
void Game::update()
{
  if(m_gameState == GameState::Playing)
  {
    m_ship.update();
    for(auto &r : m_rocks)
      r.update();
    for(auto &m : m_missile)
      m.update();

    checkCollisions();
     checkMissileCollisions();

  }
}

void Game::checkMissileCollisions()
{
  for(auto &m : m_missile)
  {
  auto mpos=m.getPos();
  float mrad=2.0f;
    for(auto r : m_rocks)
    {
      auto rpos = r.getPos();
      auto rrad = r.getRadius();
      float dist=(mpos - rpos).lengthSquared();
      float minDist = mrad+rrad;
      if(dist <=(minDist * minDist))
      {
        m_score++;
        m.setDead();
      }
    }  
  }

  for(auto &m : m_missile)
  {
   int size=RenderGlobals::getSize();

    auto p=m.getPos();
    if( p.m_x <=-size || p.m_x >=size ||
    p.m_y<=-size || p.m_y >= size )
    {
      m.setDead();
    }
  }


  if(m_missile.size() !=0)
  {
    m_missile.erase(std::remove_if(std::begin(m_missile), std::end(m_missile),[](auto &m){ return !m.isAlive();} ),std::end(m_missile));
  }



}



void Game::checkCollisions()
{
  // get Ship Pos and Rad
  auto spos=m_ship.getPos();
  auto srad=m_ship.getRadius();
  // for each rock see if we hit!
  for(auto r : m_rocks)
  {
    auto rpos = r.getPos();
    auto rrad = r.getRadius();
    float dist=(spos - rpos).lengthSquared();
    float minDist = srad+rrad;
    if(dist <=(minDist * minDist))
    {
      m_ship.changeLife(-10);
      if(m_ship.getLife()<=0)
      {
        m_gameState=GameState::GameOver;
      }
    }

  }

}

void Game::fire(bool _state)
{
  if(m_missile.size() <= m_maxMissiles)
  {
    if(_state == true)
    {
      m_missile.push_back(Missile(m_ship.getPos(), m_ship.getRotation()));
    }
  }
}

void Game::updateShip(float _rotation)
{
  m_ship.updateRotation(_rotation);
}