#include <iostream>
#include "Jeux.h"

Jeux::Jeux(int gridSize, Joueur* j1) : m_player1(j1), m_current_player(j1), m_grille(Grille(gridSize)){
	m_nb_players = 1;
}

Jeux::Jeux(int gridSize, Joueur* j1, Joueur* j2) : m_player1(j1), m_player2(j2), m_current_player(j1), m_grille(Grille(gridSize)){
	m_nb_players = 2;
}

Jeux::~Jeux(){

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