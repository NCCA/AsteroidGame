#ifndef MISSILE_H_
#define MISSILE_H_
#include <ngl/Vec3.h>

class Missile
{
  private :
    Missile();
    void update();
    void draw() const;
  public :
    ngl::Vec3 m_pos;
    ngl::Vec3 m_dir;

};


#endif