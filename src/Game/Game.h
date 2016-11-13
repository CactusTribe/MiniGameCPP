#ifndef JEUX_H
#define JEUX_H

#include <SFML/Graphics.hpp>
#include <string>
#include "../Player/Player.h"
#include "../Board/Board.h"
#include "../IHM.h"


class Game{

public:
  Game(std::string name, int gridSize, Player& player);
  virtual ~Game();

  const std::string name() const;

  virtual void draw(IHM& render)= 0;

  virtual void action(bool haveEvent, sf::Event e)=0;

protected:

  const std::string _name;
  Board _board;
  Player& _player;

};

#endif
