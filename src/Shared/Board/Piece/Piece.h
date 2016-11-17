#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include "../Board.h"
#include "PieceType.h"
#include "../Pos2D.h"

class Piece {

  public:
    Piece(PieceType type);

    ~Piece();

    PieceType type() const;
    bool hasBoard() const;
    Board* board() const;
    Pos2D pos() const;
    virtual void draw(sf::RenderTarget* target) const;

    virtual bool canMovedBy(const Board* board, Piece* source, Pos2D src) const;

    // return true stop event
    virtual bool onMovedBy(Board* board, Piece* source, Pos2D src);

    virtual bool canMovedTo(const Board* board, Piece* target, Pos2D dst) const;

    // return true stop event
    virtual bool onMovedTo(Board* board, Piece* target, Pos2D dst);

  protected:
    void pos(Pos2D pos);
    void board(Board* board);

    const PieceType _type;
    Board* _board;
    Pos2D _pos;

  friend Board;
};

#endif
