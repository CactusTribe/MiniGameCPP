#ifndef TAQUIN_H
#define TAQUIN_H

#include <string>
#include "Game.h"

class Taquin : public Game{
public:
  Taquin(std::string name, int window_size, int grid_size, Player& j);
  ~Taquin();

  void init();

private:
  void human_loop(sf::Event e);
  void computer_loop();

  int m_blank_X = 0;
  int m_blank_Y = 0;
};

#endif
