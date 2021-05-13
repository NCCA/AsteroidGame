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

void Ship::draw()
{
  ngl::ShaderLib::use(ngl::nglColourShader);
  ngl::ShaderLib::setUniform("Colour",1.0f,1.0f,1.0f,1.0f);
  ngl::Transformation tx;
  tx.setPosition(m_pos);
  tx.setScale(4.0f,4.0f,4.0f);
  ngl::ShaderLib::setUniform("MVP", RenderGlobals::getVPMatrix()* tx.getMatrix() );
  // std::cout<<RenderGlobals::getVPMatrix()<<'\n';
  // std::cout<<RenderGlobals::getViewMatrix()<<'\n';
  // std::cout<<RenderGlobals::getProjectionMatrix()<<'\n';

  ngl::VAOPrimitives::draw("teapot");
}
void Ship::update()
{

}
