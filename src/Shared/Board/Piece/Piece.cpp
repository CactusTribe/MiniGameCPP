#include "Piece.h"
#include "../Pos2D.h"

Piece::Piece(PieceType type)
  : _type(type), _pos(-1,-1)
{
}

Piece::~Piece()
{
}

PieceType Piece::type() const
{
  return _type;
}

bool Piece::hasBoard() const
{
  return _board;
}

Board* Piece::board() const
{
  return _board;
}

Pos2D Piece::pos() const
{
  return _pos;
}

void Piece::pos(Pos2D pos)
{
  _pos= pos;
}

void Piece::board(Board* board)
{
  _board= board;
}

void Piece::draw(sf::RenderTarget* target) const
{;}

bool Piece::canMovedBy(const Board* board, Piece* source, Pos2D src) const
{
  return true;
}

bool Piece::onMovedBy(Board* board, Piece* source, Pos2D src)
{
  return false;
}

bool Piece::canMovedTo(const Board* board, Piece* target, Pos2D dst) const
{
  return true;
}

bool Piece::onMovedTo(Board* board, Piece* target, Pos2D dst)
{
  return false;
}
