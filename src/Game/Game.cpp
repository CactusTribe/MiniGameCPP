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

void Game::draw(IHM& render)
{
    // Remplissage de l'écran
    render.app()->clear(sf::Color(255, 255, 255));
    // Affiche la grille
    _board.draw(render);
    // Affichage de la fenêtre à l'écran
    render.app()->display();
}
