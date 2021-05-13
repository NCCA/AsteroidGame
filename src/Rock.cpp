#include "Rock.h"
#include <ngl/ShaderLib.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/Random.h>
#include <ngl/Transformation.h>
#include "RenderGlobals.h"
Rock::Rock()
{
  reset();

}

void Rock::reset()
{
  int size=RenderGlobals::getSize();
  m_pos = ngl::Random::getRandomVec3()*float(size);
  m_pos.m_y=0.0f;
  m_scale = 1.0f + ngl::Random::randomPositiveNumber(8.0f);
  m_rotation = ngl::Random::randomNumber(2.0);
  m_dir = ngl::Random::getRandomNormalizedVec3();
  m_dir.m_y=0.0f;
  m_maxLife = static_cast<int>(ngl::Random::randomPositiveNumber(500))+20;
  m_life=0;

}

ngl::Vec3 Rock::getPos()const
{
  return m_pos;
}
float Rock::getRadius()const
{
  return m_scale;
}

void Rock::draw()
{
  ngl::ShaderLib::use(ngl::nglColourShader);
  ngl::ShaderLib::setUniform("Colour",1.0f,0.0f,0.0f,1.0f);
  ngl::Transformation tx;
  tx.setPosition(m_pos);
  tx.setScale(m_scale,1.0,m_scale);
  tx.setRotation(0,m_rotation,0);
  ngl::ShaderLib::setUniform("MVP", RenderGlobals::getVPMatrix()*tx.getMatrix());
  ngl::VAOPrimitives::draw("rock");
}
void Rock::update()
{
  m_pos += m_dir;
  m_rotation += ngl::Random::randomPositiveNumber(3.0f);
  // check walls
  int size=RenderGlobals::getSize();
  if(m_pos.m_x <= -size)
  {
    m_dir.m_x = -m_dir.m_x ;
  }
  if(m_pos.m_x >= size)
  {
    m_dir.m_x = -m_dir.m_x ;
  }
  
  if(m_pos.m_z <= size) // top
  {
    m_dir.m_z = -m_dir.m_z ;
  }
  if(m_pos.m_z >= -size)
  {
    m_dir.m_z = -m_dir.m_z ;
  }
  
  // check life
  if(++m_life > m_maxLife)
  {
    reset();
  }




}
