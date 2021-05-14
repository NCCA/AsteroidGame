#include "Ship.h"
#include <ngl/NGLStream.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/ShaderLib.h>
#include <ngl/Transformation.h>
#include <ngl/Util.h>
#include "RenderGlobals.h"
Ship::Ship(const ngl::Vec3 &_pos) : m_pos{_pos}
{

}

void Ship::setPos(const ngl::Vec3 &_p)
{
  m_pos=_p;
}

void Ship::updateRotation(float _rotation)
{
  m_rot+=_rotation;
}

ngl::Vec3 Ship::getPos() const
{
  return m_pos;
}

float Ship::getRadius() const
{
  return m_radius;
}

void Ship::resetShip()
{
  m_life= 1000;
}

void Ship::draw()
{
  ngl::ShaderLib::use(ngl::nglColourShader);
  ngl::ShaderLib::setUniform("Colour",1.0f,1.0f,1.0f,1.0f);
  ngl::Transformation tx;
  tx.setPosition(m_pos);
  tx.setScale(4.0f,4.0f,4.0f);
  tx.setRotation(0,180.0+m_rot,0);
  ngl::ShaderLib::setUniform("MVP", RenderGlobals::getVPMatrix()* tx.getMatrix() );
  // std::cout<<RenderGlobals::getVPMatrix()<<'\n';
  // std::cout<<RenderGlobals::getViewMatrix()<<'\n';
  // std::cout<<RenderGlobals::getProjectionMatrix()<<'\n';

  //ngl::VAOPrimitives::draw("teapot");
  RenderGlobals::drawMesh("ship");
}
void Ship::update()
{

}


int Ship::getLife() const
{
  return m_life;
}
void Ship::changeLife(int _dLife)
{
  m_life += _dLife;
}
