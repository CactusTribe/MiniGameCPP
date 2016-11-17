#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Taquin.h"

using namespace sf;

Taquin::Taquin(std::string name, int boardSize, Player& player)
  : Game(name, boardSize, player)
{

  std::vector<int> numbers;
  int gridsize = _board.size();
  for(int i=0; i < (gridsize * gridsize); i++){
    numbers.push_back(i);
  }

  // Remplisage aléatoire de la grille
  for(int i=0; i < gridsize; i++){
    for(int j=0; j < gridsize; j++){

        int random = rand() % numbers.size();
        int choice = numbers[random];
        numbers.erase(numbers.begin() + (random));

     /*   if(choice > 0)
          _board.changePiece(Piece(PieceType::INTEGER, choice), j, i);
        else{
          _board.changePiece(Piece(PieceType::EMPTY, 0), j, i);
          _blank_X = j;
          _blank_Y = i;
        }
*/
    }
  }
}

Taquin::~Taquin(){
}

void Taquin::action(bool haveEvent, Event e)
{
/*    switch(_player.choiceAction(haveEvent, e) ){

      case PlayerAction::Up :
        if(_blank_Y < _board.size()-1){
          int old_x = _blank_X;
          int old_y = _blank_Y+1;

          _board.changePiece(_board.get(old_x, old_y), _blank_X, _blank_Y);
          _board.changePiece(Piece(PieceType::EMPTY, 0), old_x, old_y);
          _blank_X = old_x;
          _blank_Y = old_y;
        }
      break;

      case PlayerAction::Down :
        if(_blank_Y > 0){
          int old_x = _blank_X;
          int old_y = _blank_Y-1;
          _board.changePiece(_board.get(old_x, old_y), _blank_X, _blank_Y);
          _board.changePiece(Piece(PieceType::EMPTY, 0), old_x, old_y);
          _blank_X = old_x;
          _blank_Y = old_y;
        }
      break;

      case PlayerAction::Left :
        if(_blank_X < _board.size()-1){
          int old_x = _blank_X+1;
          int old_y = _blank_Y;
          _board.changePiece(_board.get(old_x, old_y), _blank_X, _blank_Y);
          _board.changePiece(Piece(PieceType::EMPTY, 0), old_x, old_y);
          _blank_X = old_x;
          _blank_Y = old_y;
        }
      break;

      case PlayerAction::Right :
        if(_blank_X > 0){
          int old_x = _blank_X-1;
          int old_y = _blank_Y;

          _board.changePiece(_board.get(old_x, old_y), _blank_X, _blank_Y);
          _board.changePiece(Piece(PieceType::EMPTY, 0), old_x, old_y);
          _blank_X = old_x;
          _blank_Y = old_y;
        }
      break;

      default:
      break;
    } */
}


