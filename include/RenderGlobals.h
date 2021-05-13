#ifndef RENDERGLOBALS_H_
#define RENDERGLOBALS_H_
#include <ngl/Mat4.h>

class RenderGlobals
{
  public :
    RenderGlobals(int _size);
    static ngl::Mat4 getViewMatrix();
    static ngl::Mat4 getProjectionMatrix();
    static ngl::Mat4 getVPMatrix();
    static int getSize() { return s_size;}
  private :
    static int s_size;
    static bool s_isInitialized;
    static ngl::Mat4 s_viewMatrix;
    static ngl::Mat4 s_projectMatrix;
    static ngl::Mat4 s_VPMatrix;;

};


#endif