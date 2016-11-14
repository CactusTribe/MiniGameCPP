#include <iostream>
#include "IHM.h"
#include "Game/Game.h"
#include "Player/PlayerHuman.h"
#include "Player/PlayerRobot.h"
#include "Game/Taquin.h"
#include "Game/Sokoban.h"

using namespace std;
using namespace sf;

int main(int argc, char** argv)
{
  PlayerHuman j_human("Lois l'Human");
  PlayerRobot j_robot("Jean le Robot");
  //Taquin game("Taquin", 4, j_robot);
  Sokoban game("Sokoban", 8, j_human);

  IHM render(600, "Projet :: Langages a objets avances M1 :: Joaquim Lefranc et Jerome Skoda");

  Event event;
  while(render.app()->isOpen())
  {
    bool newEvent= render.app()->pollEvent(event);
    game.action( newEvent, event);
    if(newEvent && (event.type == Event::Closed))
      return 0;
    game.draw(render);
    sleep(milliseconds(20));
  }
  return 0;
}
