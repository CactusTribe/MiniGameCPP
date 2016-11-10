#include <iostream>
#include "Grille.h"
#include "CaseType.h"

Grille::Grille(int size) : m_size(size), m_matrice(size, std::vector<Case>(size, Case(CaseType::EMPTY, 0))){

}

Grille::~Grille(){

}

Case Grille::get(int x, int y){
	return m_matrice[y][x];
}

int Grille::getSize(){
	return m_size;
}

bool Grille::changeCase(Case c, int x, int y){
	if(x < m_size && y < m_size){
		m_matrice[y][x] = c;

		return true;
	}
	else{
		return false;
	}
}

std::ostream& operator<<(std::ostream& out, const Grille& g){

	out << std::endl;

	for(int i=0; i < g.m_size ; i++){

		for(int k=0; k < g.m_size ; k++){
			out << "----";
		}
		out << std::endl;

		out << "|";

		for(int j=0; j < g.m_size ; j++){
			out << " " << g.m_matrice[j][i] << " |";
		}
		out << std::endl;
	}

		for(int k=0; k < g.m_size ; k++){
			out << "----";
		}
		out << std::endl;

	return out;
}