#include "Piece2048.h"
#include "NumberPiece.h"
#include "Piece2048Type.h"
#include "Empty.h"

NumberPiece2048::NumberPiece2048(int factor)
: Piece2048( Piece2048Type::NUMBER, std::to_string(factor) ), _factor(factor)
{
  _value= _factor;
  switch(_factor)
  {
    case 2:
      Piece2048::StringPiece::_background.loadFromFile("sprites/Mult2.png");
      break;
    case 3:
      Piece2048::StringPiece::_background.loadFromFile("sprites/Mult3.png");
      break;
    case 4:
      Piece2048::StringPiece::_background.loadFromFile("sprites/Mult4.png");
      break;
  }
}

NumberPiece2048::~NumberPiece2048()
{
}

int NumberPiece2048::value() const
{
  return _value;
}

int NumberPiece2048::factor() const
{
  return _factor;
}

NumberPiece2048& NumberPiece2048::increase()
{
  _value = _value * _factor;
  text(std::to_string(_value) );
  return *this;
}

bool NumberPiece2048::canMovedBy(const Board* board, Piece* source, Pos2D src) const
{
  if(source->type() == Piece2048Type::NUMBER)
  {
    NumberPiece2048* number= dynamic_cast<NumberPiece2048*>(source);
    if(number->factor() == factor()
        && number->value() == value()
        && !number->merge() && !merge())
      return true;
  }

  return false;
}

bool NumberPiece2048::onMovedBy(Board* board, Piece* source, Pos2D src)
{
  if(source->type() == Piece2048Type::NUMBER)
  {
    dynamic_cast<NumberPiece2048*>(source)
      ->increase()
      .merge(true);
  }
  delete this;
  return false;
}

bool NumberPiece2048::canMovedTo(const Board* board, Piece* target, Pos2D dst) const
{
  return true;
}

bool NumberPiece2048::onMovedTo(Board* board, Piece* target, Pos2D dst)
{
  board->push(new Empty2048Piece(), pos());
  return false;
}

