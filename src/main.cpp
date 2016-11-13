#include <iostream>
#include "SuperGame.h"
#include "Taquin.h"

using namespace std;

int main(){

  Joueur j1("Joueur 1", JoueurType::HUMAN);
  Joueur j2("Joueur 2", JoueurType::COMPUTER);

  Taquin taquin("Taquin", 400, 4, j1);
  taquin.init();
  taquin.start();

  return 0;
}
