#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Taquin.h"
#include "SuperGame.h"


using namespace sf;

Taquin::Taquin(std::string name, int window_size, int grid_size, Joueur& j) : Jeux(name, window_size, grid_size, j){

	srand (time(NULL));
}

Taquin::~Taquin(){
}

void Taquin::init(){
	// Tableau des nombres disponibles	
	std::vector<int> numbers;
	int gridsize = m_grille.getSize();
	for(int i=0; i < (gridsize * gridsize); i++){
		numbers.push_back(i);
	}

	// Remplisage aléatoire de la grille
	for(int i=0; i < gridsize; i++){
		for(int j=0; j < gridsize; j++){

				int random = rand() % numbers.size();
				int choice = numbers[random];
				numbers.erase(numbers.begin() + (random));

				if(choice > 0)
					m_grille.changeCase(Case(CaseType::INTEGER, choice), j, i);
				else{
					m_grille.changeCase(Case(CaseType::EMPTY, 0), j, i);
					m_blank_X = j;
					m_blank_Y = i;
				}

		}
	}
}

void Taquin::human_loop(Event e){
	if(e.type == Event::KeyPressed){

		switch(e.key.code){

			case Keyboard::Up :
				if(m_blank_Y < m_grille.getSize()-1){
					int old_x = m_blank_X;
					int old_y = m_blank_Y+1;

					m_grille.changeCase(m_grille.get(old_x, old_y), m_blank_X, m_blank_Y);
					m_grille.changeCase(Case(CaseType::EMPTY, 0), old_x, old_y);
					m_blank_X = old_x;
					m_blank_Y = old_y;

					update();
				}
			break;

			case Keyboard::Down :
				if(m_blank_Y > 0){
					int old_x = m_blank_X;
					int old_y = m_blank_Y-1;

					m_grille.changeCase(m_grille.get(old_x, old_y), m_blank_X, m_blank_Y);
					m_grille.changeCase(Case(CaseType::EMPTY, 0), old_x, old_y);
					m_blank_X = old_x;
					m_blank_Y = old_y;

					update();
				}
			break;

			case Keyboard::Left :
				if(m_blank_X < m_grille.getSize()-1){
					int old_x = m_blank_X+1;
					int old_y = m_blank_Y;

					m_grille.changeCase(m_grille.get(old_x, old_y), m_blank_X, m_blank_Y);
					m_grille.changeCase(Case(CaseType::EMPTY, 0), old_x, old_y);
					m_blank_X = old_x;
					m_blank_Y = old_y;

					update();
				}
			break;

			case Keyboard::Right :
				if(m_blank_X > 0){
					int old_x = m_blank_X-1;
					int old_y = m_blank_Y;

					m_grille.changeCase(m_grille.get(old_x, old_y), m_blank_X, m_blank_Y);
					m_grille.changeCase(Case(CaseType::EMPTY, 0), old_x, old_y);
					m_blank_X = old_x;
					m_blank_Y = old_y;

					update();
				}
			break;

			default:
			break;
		}
	}
}

void Taquin::computer_loop(){

}

