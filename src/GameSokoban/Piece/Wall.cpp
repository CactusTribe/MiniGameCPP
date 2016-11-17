#include "Wall.h"

SokobanWallPiece::SokobanWallPiece()
  : GraphicsPiece(PieceType::Wall ,"sprites/GroundGravel_Sand.png", "sprites/WallRound_Brown.png")
{
}

SokobanWallPiece::~SokobanWallPiece()
{
}

bool SokobanWallPiece::canMovedBy(const Board* board, Piece* source, Pos2D src) const
{
  return false;
}