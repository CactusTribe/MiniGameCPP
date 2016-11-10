#ifndef JEUX_H
#define JEUX_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Joueur.h"
#include "Grille.h"

class Jeux{
public:
	Jeux(std::string name, int window_size, int gridSize, Joueur* j1);
	Jeux(std::string name, int window_size, int gridSize, Joueur* j1, Joueur* j2);
	~Jeux();

	virtual void init() = 0;
	virtual void startGame() = 0;
	virtual void eventLoop() = 0;
	virtual void update() = 0;

protected:
	std::string m_name = "";
	int m_nb_players = 0;
	Joueur* m_player1 = 0;
	Joueur* m_player2 = 0;
	Joueur* m_current_player = 0;
	Grille m_grille;
	int m_window_size = 0;
	sf::RenderWindow* m_app;

friend std::ostream& operator<<(std::ostream& out, const Jeux& j);
};

#endif 