#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include "PlayerType.h"

class Player{
public:
  Player(std::string name, PlayerType type);
  ~Player();

  std::string getName();
  PlayerType getType();

private:
  std::string m_name;
  PlayerType m_type;

friend std::ostream& operator<<(std::ostream& out, const Player& j);
};

#endif
