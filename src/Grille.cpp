#include <iostream>
#include "Grille.h"
#include "CaseType.h"

Grille::Grille(int largeur) : m_largeur(largeur), m_matrice(largeur, std::vector<Case>(largeur, Case(CaseType::EMPTY, 0))){

}

Grille::~Grille(){

}

bool Grille::changeCase(Case c, int i, int j){
	if(i < m_largeur && j < m_largeur){
		m_matrice[i][j] = c;

		return true;
	}
	else{
		return false;
	}
}

std::ostream& operator<<(std::ostream& out, const Grille& g){

	out << std::endl;

	for(int i=0; i < g.m_largeur ; i++){

		for(int k=0; k < g.m_largeur ; k++){
			out << "----";
		}
		out << std::endl;

		out << "|";

		for(int j=0; j < g.m_largeur ; j++){
			out << " " << g.m_matrice[j][i] << " |";
		}
		out << std::endl;
	}

		for(int k=0; k < g.m_largeur ; k++){
			out << "----";
		}
		out << std::endl;

	return out;
}