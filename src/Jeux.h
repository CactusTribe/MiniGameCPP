#ifndef JEUX_H
#define JEUX_H

#include <string>
#include "Joueur.h"
#include "Grille.h"

class Jeux{
public:
	Jeux(int gridSize, Joueur* j1);
	Jeux(int gridSize, Joueur* j1, Joueur* j2);
	~Jeux();

	virtual void startGame() = 0;

protected:
	std::string m_name = "";
	int m_nb_players = 0;
	Joueur* m_player1 = 0;
	Joueur* m_player2 = 0;
	Joueur* m_current_player = 0;
	Grille m_grille;

friend std::ostream& operator<<(std::ostream& out, const Jeux& j);
};

#endif 