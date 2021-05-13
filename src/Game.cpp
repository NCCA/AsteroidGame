#include "Game.h"
#include "RenderGlobals.h"
#include <cstdlib>
#include <ngl/VAOPrimitives.h>
#include <ngl/Random.h>
#include <iostream>
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

    checkCollisions();
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

void Game::updateShip(float _rotation)
{
  m_ship.updateRotation(_rotation);
}