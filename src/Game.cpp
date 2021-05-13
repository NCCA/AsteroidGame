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


}

void Game::draw() 
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  m_ship.draw();
  for(auto r : m_rocks)
    r.draw();
}

void Game::update()
{
  m_ship.update();
  for(auto &r : m_rocks)
    r.update();

  checkCollisions();
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
      std::cout<<"hit? \n";
    }

  }

}

void Game::updateShip(float _rotation)
{
  m_ship.updateRotation(_rotation);
}