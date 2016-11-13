#include <iostream>
#include "Game/Taquin.h"

using namespace std;

int main(){

  Player j1("Human", PlayerType::HUMAN);
  Player j2("Robot", PlayerType::COMPUTER);

  Taquin taquin("Taquin", 400, 4, j1);



  taquin.init();
  taquin.start();

  return 0;
}
