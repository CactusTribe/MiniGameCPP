#ifndef Piece2048_H
#define Piece2048_H

#include "../../Shared/Board/Piece/StringPiece.h"

class Piece2048 : public StringPiece {

  public:
    Piece2048(int type, std::string value);
    virtual ~Piece2048();
    bool merge() const;
    Piece2048& merge( bool merge );

  private:
    bool _merge= false;
};

#endif
