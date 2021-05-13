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
    void updateRotation(float _rotation);
    ngl::Vec3 getPos() const;
    float getRadius() const;
    int getLife() const;
    void changeLife(int _dLife);
    void resetShip();
  private :
    ngl::Vec3 m_pos;
    float m_rot=0;
    float m_radius=1.0f;
    int m_life=1000;

};


#endif