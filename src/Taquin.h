#ifndef TAQUIN_H
#define TAQUIN_H

#include "Jeux.h"

class Taquin : public Jeux{
public:
	Taquin(int gridSize, Joueur* j1);
	~Taquin();

	void startGame();
};

#endif 