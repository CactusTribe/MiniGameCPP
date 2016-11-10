#ifndef TAQUIN_H
#define TAQUIN_H

#include <string>
#include "Jeux.h"

class Taquin : public Jeux{
public:
	Taquin(std::string name, int window_size, int grid_size, Joueur* j1);
	~Taquin();

	void init();
	void startGame();
	void eventLoop();
	void update();

private:
	int m_blank_X = 0;
	int m_blank_Y = 0;
};

#endif 