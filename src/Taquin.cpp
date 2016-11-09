#include <iostream>
#include "Taquin.h"

Taquin::Taquin(int gridSize, Joueur* j1) : Jeux(gridSize, j1){
	m_name = "Taquin";
}

Taquin::~Taquin(){

}

void Taquin::startGame(){
	std::cout << *this;

	std::cout << m_grille;

	m_grille.changeCase(Case(CaseType::INTEGER, 16), 2, 3);

	std::cout << m_grille;
}