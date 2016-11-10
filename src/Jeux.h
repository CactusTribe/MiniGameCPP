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

	virtual void start(){
		std::cout << *this;
		update();

		// Boucle principale
		while (m_app->isOpen()){

			sf::Event event;
			while (m_app->pollEvent(event)){
				if (event.type == sf::Event::Closed){
					m_app->close();
					break;
				}

				// Actions humaines ou de l'ordinateur
				if(m_player.getType() == JoueurType::HUMAN)
					human_loop(event);
				else if(m_player.getType() == JoueurType::COMPUTER)
					computer_loop();
			}

			sleep(sf::milliseconds(10));
		}
	}
	
protected:

	virtual void human_loop(sf::Event e) = 0;
	virtual void computer_loop() = 0;
	
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