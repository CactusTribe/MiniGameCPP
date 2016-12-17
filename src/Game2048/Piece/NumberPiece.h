#ifndef NumberPiece2048_H
#define NumberPiece2048_H

#include "Piece2048.h"

class NumberPiece2048 : public Piece2048 {

  public:
    NumberPiece2048(int value);
    virtual ~NumberPiece2048();

    NumberPiece2048& increase();
    int factor() const;
    int value() const;

    virtual bool canMovedBy(const Board* board, Piece* source, Pos2D src) const;
    virtual bool onMovedBy(Board* board, Piece* source, Pos2D src);
    virtual bool canMovedTo(const Board* board, Piece* target, Pos2D dst) const;
    virtual bool onMovedTo(Board* board, Piece* target, Pos2D dst);

  private:
    const int _factor;
    int _value;
};

#endif
