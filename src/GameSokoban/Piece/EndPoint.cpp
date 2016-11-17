#include "EndPoint.h"
#include "../PieceType.h"

SokobanEndPointPiece::SokobanEndPointPiece()
  : GraphicsPiece(PieceType::END_POINT ,"sprites/GroundGravel_Sand.png", "sprites/EndPoint_Purple.png")
{
}

SokobanEndPointPiece::~SokobanEndPointPiece()
{
}