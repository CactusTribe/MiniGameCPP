#ifndef TaquinNumberPiece_H
#define TaquinNumberPiece_H

#include "../../Shared/Board/Piece/StringPiece.h"

class TaquinNumberPiece : public StringPiece {

  public:
    TaquinNumberPiece(const int value);

    virtual ~TaquinNumberPiece();

};

#endif
