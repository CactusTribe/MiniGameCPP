#ifndef JEUX_H
#define JEUX_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Joueur.h"
#include "Grille.h"

class Jeux{
public:
	Jeux(std::string name, int window_size, int gridSize, Joueur& j);
	~Jeux();

	virtual void init() = 0;
	virtual void startGame() = 0;
	virtual void eventLoop() = 0;
	
protected:

	virtual void update(){
		// Remplissage de l'écran
		m_app->clear(sf::Color(255, 255, 255));

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

	std::string m_name = "";
	int m_window_size = 0;
	sf::RenderWindow* m_app;
	Grille m_grille;
	Joueur& m_player;

friend std::ostream& operator<<(std::ostream& out, const Jeux& j);
};

#endif 