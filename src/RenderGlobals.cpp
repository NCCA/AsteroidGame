#include "RenderGlobals.h"
#include <ngl/Util.h>
#include <iostream>
int RenderGlobals::s_size=100;
bool RenderGlobals::s_isInitialized=false;
ngl::Mat4 RenderGlobals::s_viewMatrix;
ngl::Mat4 RenderGlobals::s_projectMatrix;
ngl::Mat4 RenderGlobals::s_VPMatrix;
RenderGlobals::RenderGlobals(int _size) 
{

  if(s_isInitialized !=true)
  {
    std::cout<<"Init Render Gloabls\n";
    s_size=_size;
    s_viewMatrix = ngl::lookAt({0,10,0},{0,0,0},{0,0,1});
    s_projectMatrix = ngl::ortho(-_size,_size,-_size,_size,0.01f,100.0f);
    s_VPMatrix=s_projectMatrix*s_viewMatrix;
  }
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
