#ifndef GRILLE_H
#define GRILLE_H

#include <iostream>
#include <vector>
#include "Case.h"

class Grille{
public:
	Grille(int largeur);
	~Grille();

	bool changeCase(Case c, int i, int j);

private:
	int m_largeur = 0;
	std::vector<std::vector<Case>> m_matrice;

friend std::ostream& operator<<(std::ostream& out, const Grille& g);


};

#endif 