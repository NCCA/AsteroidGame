#ifndef SHIP_H_
#define SHIP_H_

#include <ngl/Vec3.h>

class Ship
{
  public :
    Ship()=default;
    Ship(const ngl::Vec3 &_pos);
    void setPos(const ngl::Vec3 &_p);
    void draw();
    void update();
  private :
    ngl::Vec3 m_pos;
    float m_rot=0;
};


#endif