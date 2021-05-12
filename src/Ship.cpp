#include "Ship.h"
#include <ngl/NGLStream.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/ShaderLib.h>
#include <ngl/Transformation.h>
#include <ngl/Util.h>
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
  ngl::Mat4 view = ngl::lookAt({0,10,0},{0,0,0},{0,0,1});
  ngl::Mat4 project = ngl::ortho(-100,100,-100,100,0.01f,1000.0f);
  ngl::Transformation tx;
  std::cout<<m_pos<<'\n';
  tx.setPosition(m_pos);
  tx.setScale(4.0f,4.0f,4.0f);
  std::cout<<tx.getMatrix()<<'\n';
  ngl::ShaderLib::setUniform("MVP",project * view * tx.getMatrix() );
  ngl::VAOPrimitives::draw("teapot");
}
void Ship::update()
{

}
