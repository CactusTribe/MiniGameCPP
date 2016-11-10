#include <iostream>
#include "Joueur.h"
#include "JoueurType.h"
#include "Taquin.h"

using namespace std;

int main(){

	Joueur j1("Joueur 1", JoueurType::HUMAN);
	Joueur j2("Joueur 2", JoueurType::COMPUTER);

	Taquin taquin("Taquin", 400, 8, &j1);
	taquin.init();
	taquin.startGame();

	return 0;
}