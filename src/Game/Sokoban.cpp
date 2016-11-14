#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Sokoban.h"

using namespace sf;

Sokoban::Sokoban(std::string name, int boardSize, Player& player)
  : Game(name, boardSize, player)
{

  int gridsize = _board.getSize();
  // Remplisage aléatoire de la grille
  for(int i=0; i < gridsize; i++){
    for(int j=0; j < gridsize; j++){

      int random = rand() % 5;
      if(random == 0)
        _board.changePiece(Piece(PieceType::EMPTY, 0), j, i);
      else if(random == 1)
        _board.changePiece(Piece(PieceType::WALL, 0), j, i);
      else if(random == 2)
        _board.changePiece(Piece(PieceType::BOX, 0), j, i);
      else if(random == 3)
        _board.changePiece(Piece(PieceType::END_POINT, 0), j, i);
      else if(random == 4)
        _board.changePiece(Piece(PieceType::PLAYER_UP, 0), j, i);
    }
  }
}

Sokoban::~Sokoban(){
}

void Sokoban::action(bool haveEvent, Event e)
{
    switch(_player.choiceAction(haveEvent, e) ){

      case PlayerAction::Up :

      break;

      case PlayerAction::Down :

      break;

      case PlayerAction::Left :

      break;

      case PlayerAction::Right :

      break;

      default:
      break;
    }
  
}
