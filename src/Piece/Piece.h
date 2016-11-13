#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>
#include "PieceType.h"

class Piece {

  public:
    Piece(PieceType type, int value);
    ~Piece();

    PieceType getType();
    int getValue();
    void setValue(int i);
    void draw(sf::RenderTarget* target, int size, int x, int y);

  private:
    int m_value = 0;
    PieceType m_type;

  friend std::ostream& operator<<(std::ostream& out, const Piece& c);

};

#endif
