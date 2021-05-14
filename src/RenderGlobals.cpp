#include "RenderGlobals.h"
#include <ngl/Util.h>
#include <iostream>
#include <ngl/VAOPrimitives.h>

int RenderGlobals::s_size=100;
bool RenderGlobals::s_isInitialized=false;
ngl::Mat4 RenderGlobals::s_viewMatrix;
ngl::Mat4 RenderGlobals::s_projectMatrix;
ngl::Mat4 RenderGlobals::s_VPMatrix;
std::unordered_map<std::string,std::unique_ptr<ngl::Obj>> RenderGlobals::s_models;

RenderGlobals::RenderGlobals(int _size) 
{

  if(s_isInitialized !=true)
  {
    std::cout<<"Init Render Gloabls\n";
    s_size=_size;
    s_viewMatrix = ngl::lookAt({0,10,0},{0,0,0},{0,0,1});
    s_projectMatrix = ngl::ortho(-_size,_size,-_size,_size,0.01f,100.0f);
    s_VPMatrix=s_projectMatrix*s_viewMatrix;

    ngl::VAOPrimitives::createSphere("rock",1.0f,4);

    std::unique_ptr<ngl::Obj> ship = std::make_unique<ngl::Obj>("models/ship.obj");
    ship->createVAO();
    s_models["ship"] = std::move(ship);
    std::unique_ptr<ngl::Obj> missile = std::make_unique<ngl::Obj>("models/missle.obj");
    missile->createVAO();
    s_models["missile"] = std::move(missile);


    std::unique_ptr<ngl::Obj> mrock = std::make_unique<ngl::Obj>("models/mediumrock.obj");
    mrock->createVAO();
    s_models["mediumRock"] = std::move(mrock);



  }
}

void RenderGlobals::drawMesh(const std::string &_name)
{
  s_models[_name]->draw();
}



ngl::Mat4 RenderGlobals::getViewMatrix()
{
  return s_viewMatrix;
}
ngl::Mat4 RenderGlobals::getProjectionMatrix()
{
  return s_projectMatrix;
}
ngl::Mat4 RenderGlobals::getVPMatrix()
{
  return s_VPMatrix;
}
