#ifndef GAME_H_
#define GAME_H_
#include "Ship.h"
#include "Rock.h"
#include "Missile.h"
#include <ngl/Text.h>
#include <memory>
class Game
{
  public :
    Game(int _arenaSize);
    void draw();
    void update(); // what do we update? keys? Mouse? Sound? how do we pass from SDL to here?
    void updateShip(float _rotation);
    enum class GameState{MainMenu,Playing,GameOver};
    void changeGameState(GameState _state);
    void fire(bool _state);
  private :
    void checkCollisions();
    void checkMissileCollisions();
    int m_arenaSize=0;
    Ship m_ship;
    std::vector<Rock> m_rocks;
    std::vector<Missile> m_missile;
    std::unique_ptr<ngl::Text> m_text;
    int m_score=0;
    GameState m_gameState=GameState::MainMenu;
    int m_maxMissiles = 5;
};


#endif