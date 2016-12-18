#include <iostream>
#include "Shared/IHM.h"
#include "Shared/Game.h"
#include "Shared/Player/PlayerHuman.h"
#include "Shared/Player/PlayerRobot.h"
#include "GameTaquin/Taquin.h"
#include "GameSokoban/Sokoban.h"
#include "Game2048/Game2048.h"
#include "Game2048/Game2048Variante1.h"

using namespace std;
using namespace sf;

int main(int argc, char** argv)
{
  try
  {
    std::srand(std::time(0));

    PlayerHuman j_human("Lois l'Human");
    PlayerRobot j_robot("Jean le Robot");
    //Taquin game("Taquin", 4, j_human);
    //Sokoban game("Sokoban", 8, j_human);
    Game2048Variante1 game("2048", 4, j_human);

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
  }
  catch (std::exception const &exc)
  {
    std::cerr << "Exception caught " << exc.what() << "\n";
  }
  catch (const char* msg)
  {
    cerr << msg << endl;
  }
  catch (...)
  {
    std::cerr << "Unknown exception caught\n";
  }
  return 0;
}
