#include <iostream>
#include "Game.h"

Game::Game(std::string name, int window_size, int gridSize, Player& j) :
    m_name(name), m_window_size(window_size), m_grille(Board(gridSize)), m_player(j){

  m_app = new sf::RenderWindow(sf::VideoMode(m_window_size, m_window_size, 32), m_name);
}


Game::~Game(){
  delete m_app;
}


std::ostream& operator<<(std::ostream& out, const Game& j){
  out << "################################################" << std::endl;
  out << "# GAME : " << j.m_name << std::endl;
  out << "# PLAYER : " << j.m_player.getName() << std::endl;
  out << "################################################" << std::endl;
  return out;
}
