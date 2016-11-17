#include "IHM.h"
#include "Board/Board.h"
#include "Board/Piece/Piece.h"
#include "Board/Pos2D.h"

using namespace sf;

IHM::IHM(int window_size, const std::string& title)
  : _window_size(window_size) {
  _app = new RenderWindow(VideoMode(_window_size, _window_size, 32), title);
}

IHM::~IHM() {
  _app->close();
  delete _app;
}

sf::RenderWindow* IHM::app() {
  return _app;
}

int IHM::window_size() {
  return _window_size;
}



std::ostream& operator<<(std::ostream& out, const Piece& piece){
  // Enum est strictement typé...
  switch(piece.type())
   {
    case PieceType::Empty:
      out << " ";
    break;
    case PieceType::Integer:
 //     out << c._value;
    break;
    case PieceType::Factor:
      out << "x2";
    break;
    case PieceType::Box:
      out << "O";
    break;
    case PieceType::Wall:
      out << "X";
    break;
    case PieceType::Player:
    break;
    case PieceType::EndPoint:
    break;
  }
  return out;
}


std::ostream& operator<<(std::ostream& out, const Board& board)
{
  out << std::endl;

  for(int i=0; i < board.size() ; i++){

    for(int k=0; k < board.size() ; k++){
      out << "----";
    }
    out << std::endl;

    out << "|";

    for(int j=0; j < board.size() ; j++){
      out << " " << board.get(Pos2D(j,i)) << " |";
    }
    out << std::endl;
  }

    for(int k=0; k < board.size() ; k++){
      out << "----";
    }
    out << std::endl;

  return out;
}
