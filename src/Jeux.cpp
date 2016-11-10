#include <iostream>
#include "Jeux.h"

Jeux::Jeux(std::string name, int window_size, int gridSize, Joueur* j1) : 
		m_name(name), m_window_size(window_size), m_player1(j1), m_current_player(j1), m_grille(Grille(gridSize)){

	m_nb_players = 1;
	m_app = new sf::RenderWindow(sf::VideoMode(m_window_size, m_window_size, 32), m_name);
}

Jeux::Jeux(std::string name, int window_size, int gridSize, Joueur* j1, Joueur* j2) : 
		m_name(name), m_window_size(window_size), m_player1(j1), m_player2(j2), m_current_player(j1), m_grille(Grille(gridSize)){

	m_nb_players = 2;
	m_app = new sf::RenderWindow(sf::VideoMode(m_window_size, m_window_size, 32), m_name);
}

Jeux::~Jeux(){
	delete m_app;
}

std::ostream& operator<<(std::ostream& out, const Jeux& j){
	out << "################################################" << std::endl;
	out << "# GAME : " << j.m_name << std::endl;
	out << "# NB PLAYERS : " << j.m_nb_players << std::endl;
	out << "# PLAYER 1 : " << j.m_player1->getName() << std::endl;
	if(j.m_nb_players == 2){
		out << "# PLAYER 2 : " << j.m_player2->getName() << std::endl;
	}
	out << "################################################" << std::endl;
	return out;
}