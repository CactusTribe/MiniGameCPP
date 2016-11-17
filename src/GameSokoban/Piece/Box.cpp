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
    if(source->type() == PieceType::Player)
      return board->canMoveRel( (Piece *) this, src-pos()*-1);
  return false;
}