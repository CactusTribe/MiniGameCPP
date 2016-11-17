#ifndef TAQUIN_H
#define TAQUIN_H

#include <string>
#include "../Shared/Game.h"

class Taquin : public Game {

public:
  Taquin(std::string name, int boardSize, Player& player);
  virtual ~Taquin();

  virtual void action(bool haveEvent, sf::Event e);

private:
  int _blank_X = 0;
  int _blank_Y = 0;

};

#endif
