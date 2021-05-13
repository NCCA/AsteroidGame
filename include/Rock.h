#ifndef ROCK_H_
#define ROCK_H_

#include <ngl/Vec3.h>

class Rock
{
  public :
    Rock();
    void draw();
    void update();
    void reset();
    void setDead(){m_isAlive=false;};
    bool isAlive() const {return m_isAlive;}
    ngl::Vec3 getPos()const; 
    float getRadius()const; 

  private :
    ngl::Vec3 m_pos;
    ngl::Vec3 m_dir;
    float m_scale=1.0;
    float m_speed;
    bool m_isAlive = true;
    int m_life=0;
    int m_maxLife=500;
    float m_rotation=0.0f;
};

#endif