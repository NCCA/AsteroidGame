#include "Missile.h"
#include <ngl/ShaderLib.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/Transformation.h>
#include <ngl/Mat3.h>
#include "RenderGlobals.h"


Missile::Missile(const ngl::Vec3 &_pos, float _rot)
{
  m_pos = _pos;
  // somthing with rot?
  m_dir.set(1.0f,0.0f,0.f);
  ngl::Mat3 rot;
  rot.rotateY(_rot);
  m_dir = rot*m_dir;
  m_rot=_rot;
}
void Missile::update()
{
  m_pos += m_dir;
}
void Missile::draw() const
{
  ngl::ShaderLib::use(ngl::nglColourShader);
  ngl::ShaderLib::setUniform("Colour",0.0f,1.0f,0.0f,1.0f);
  ngl::Transformation tx;
  tx.setRotation(0,m_rot,90);
  tx.setPosition(m_pos);
    ngl::ShaderLib::setUniform("MVP", RenderGlobals::getVPMatrix()* tx.getMatrix() );
  ngl::VAOPrimitives::draw("missile");  
}