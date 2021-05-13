#ifndef GAME_H_
#define GAME_H_
#include "Ship.h"
#include "Rock.h"

class Game
{
  public :
    Game(int _arenaSize);
    void draw();
    void update(); // what do we update? keys? Mouse? Sound? how do we pass from SDL to here?
    void updateShip(float _rotation);
  private :
    void checkCollisions();
    int m_arenaSize=0;
    Ship m_ship;
    std::vector<Rock> m_rocks;

};


#endif