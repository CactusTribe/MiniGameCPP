#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <string>
#include "Game.h"

class Sokoban : public Game {

public:
  Sokoban(std::string name, int boardSize, Player& player);
  virtual ~Sokoban();

  virtual void action(bool haveEvent, sf::Event e);

private:
  int _player_x = 0;
  int _player_y = 0;

};

#endif
