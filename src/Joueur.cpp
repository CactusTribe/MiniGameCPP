#include <iostream>
#include "Joueur.h"

Joueur::Joueur(std::string name, JoueurType type) : m_name(name), m_type(type){

}

Joueur::~Joueur(){

}

std::string Joueur::getName(){
	return m_name;
}

JoueurType Joueur::getType(){
	return m_type;
}

std::ostream& operator<<(std::ostream& out, const Joueur& j){

	out << "# " << j.m_name << " - ";

	switch(j.m_type){
		case JoueurType::HUMAN:
			out << "HUMAN";
		break;
		case JoueurType::COMPUTER:
			out << "COMPUTER";
		break;
	}

	return out;
}