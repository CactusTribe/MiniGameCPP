#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <vector>
#include "Taquin.h"
#include "CaseType.h"

using namespace sf;

Taquin::Taquin(std::string name, int window_size, int grid_size, Joueur* j1) : Jeux(name, window_size, grid_size, j1){

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

void Taquin::startGame(){
	std::cout << *this;
	update();
	
	// Boucle principale
	while (m_app->isOpen()){
		
		eventLoop();
		sleep(milliseconds(10));
	}
}

void Taquin::eventLoop(){
	Event event;

	while (m_app->pollEvent(event)){

		if (event.type == Event::Closed)
			m_app->close();

		else if(event.type == Event::KeyPressed){

			switch(event.key.code){

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
}

void Taquin::update(){

	// Remplissage de l'écran
	m_app->clear(Color(255, 255, 255));

	int grid_size = m_grille.getSize();
	int case_size = m_window_size / grid_size;

	// Affichage de la grille
	for(int i=0; i < grid_size; i++){
		for(int j=0; j < grid_size; j++){
			m_grille.get(j,i).draw(m_app, case_size, j*case_size, i*case_size);
		}
	}

	// Affichage de la fenêtre à l'écran
	m_app->display();
}