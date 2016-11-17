#ifndef SokobanBoxPiece_H
#define SokobanBoxPiece_H

#include "../../Shared/Board/Piece/GraphicsPiece.h"

class SokobanBoxPiece : public GraphicsPiece {

  public:
    SokobanBoxPiece();

    virtual ~SokobanBoxPiece();

    virtual bool canMovedBy(const Board* board, Piece* source, Pos2D src) const;

    private:
      Piece* previousPiece;
};

#endif