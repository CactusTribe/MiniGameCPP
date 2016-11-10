#ifndef GRILLE_H
#define GRILLE_H

#include <iostream>
#include <vector>
#include "Case.h"

class Grille{
public:
	Grille(int size);
	~Grille();

	Case get(int x, int y);
	int getSize();
	bool changeCase(Case c, int x, int y);

private:
	int m_size = 0;
	std::vector<std::vector<Case>> m_matrice;

friend std::ostream& operator<<(std::ostream& out, const Grille& g);


};

#endif 