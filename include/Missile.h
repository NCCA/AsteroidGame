#ifndef MISSILE_H_
#define MISSILE_H_
#include <ngl/Vec3.h>

class Missile
{
  public :
    Missile(const Missile&)=default;
    Missile(const ngl::Vec3 &_pos , float _rot);
    void update();
    void draw() const;
    void setDead() { m_alive=false;}
    bool isAlive() const {return m_alive;}
    ngl::Vec3 getPos() const {return m_pos;}
  private :
    ngl::Vec3 m_pos;
    ngl::Vec3 m_dir;
    float m_rot=0.0f;
    bool m_alive=true;

};


#endif