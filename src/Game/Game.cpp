#include "Game.h"

Game::Game(std::string name, int boardSize, Player& player) :
   _name(name), _board(Board(boardSize)), _player(player)
{
}

const std::string Game::name() const
{
  return _name;
}

Game::~Game()
{
}

