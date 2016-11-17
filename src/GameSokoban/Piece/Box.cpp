#include "Box.h"

SokobanBoxPiece::SokobanBoxPiece()
  : GraphicsPiece(PieceType::Box ,"sprites/GroundGravel_Sand.png", "sprites/Crate_Purple.png")
{
}

SokobanBoxPiece::~SokobanBoxPiece()
{
}

bool SokobanBoxPiece::canMovedBy(const Board* board, Piece* source, Pos2D src) const
{
  if(!source)
    return false;

  if(source->type() != PieceType::Player)
    return false;

  Pos2D dir= ( src - pos() ) * -1;

  return board->canMoveRel( (Piece *) this, dir);
}

bool SokobanBoxPiece::onMovedBy(Board* board, Piece* source, Pos2D src)
{
  if(!canMovedBy(board, source, src))
    return false;

  Pos2D dir= ( src - pos() ) * -1;
  board->moveRel( (Piece *) this, dir);
  return false;
}

bool SokobanBoxPiece::onMovedTo(Board* board, Piece* target, Pos2D dst)
{
  board->push(_store, pos());
  _store= board->get(dst);
  return false;
}

