#include <iostream>
#include "Jeux.h"

Jeux::Jeux(std::string name, int window_size, int gridSize, Joueur& j) : 
		m_name(name), m_window_size(window_size), m_grille(Grille(gridSize)), m_player(j){

	m_app = new sf::RenderWindow(sf::VideoMode(m_window_size, m_window_size, 32), m_name);
}


Jeux::~Jeux(){
	delete m_app;
}


std::ostream& operator<<(std::ostream& out, const Jeux& j){
	out << "################################################" << std::endl;
	out << "# GAME : " << j.m_name << std::endl;
	out << "# PLAYER : " << j.m_player.getName() << std::endl;
	out << "################################################" << std::endl;
	return out;
}