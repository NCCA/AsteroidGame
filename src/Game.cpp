#include "Game.h"
#include "RenderGlobals.h"
#include <cstdlib>
#include <ngl/VAOPrimitives.h>
#include <ngl/Random.h>

Game::Game(int _arenaSize) : m_arenaSize{_arenaSize}
{
  glClearColor(0.2,0.2,0.2,1.0);
  ngl::Random::setSeed();
  auto pos = ngl::Random::getRandomVec3() * 30;  
  pos.m_y=0.0f; // working in x/z plane
  m_ship.setPos(pos);
  RenderGlobals g(100);


}

void Game::draw() 
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  m_ship.draw();
}

void Game::update()
{

  // glClearColor(ngl::Random::randomPositiveNumber(),ngl::Random::randomPositiveNumber(),ngl::Random::randomPositiveNumber() ,1.0);
  m_ship.update();
}