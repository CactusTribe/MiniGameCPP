#include <iostream>
#include "IHM.h"
#include "Game/Game.h"
#include "Player/PlayerHuman.h"
#include "Player/PlayerRobot.h"
#include "Game/Taquin.h"

using namespace std;
using namespace sf;

int main(int argc, char** argv)
{
  PlayerHuman j_human("Lois l'Human");
  PlayerRobot j_robot("Jean le Robot");
  Taquin game("Taquin", 4, j_robot);
  IHM render(400, "Projet - Langages à objets avancés - M1 Joaquim Lefranc & Jérôme Skoda");

  Event event;
  while(render.app()->isOpen())
  {
    while (render.app()->pollEvent(event))
    {
      game.action(true, event);
      if (event.type == Event::Closed)
        return 0;
    }
    game.action(false, event);
    game.draw(render);
    sleep(milliseconds(20));
  }
  return 0;
}
