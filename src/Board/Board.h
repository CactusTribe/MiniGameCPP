#ifndef GRILLE_H
#define GRILLE_H

#include <iostream>
#include <vector>
#include "Piece/Piece.h"
#include "../IHM.h"

class Board{
public:
  Board(int size);
  ~Board();

  Piece get(int x, int y);
  int getSize();
  bool changePiece(Piece c, int x, int y);
  void draw(IHM& render);


private:
  int m_size = 0;
  std::vector<std::vector<Piece>> m_matrice;

friend std::ostream& operator<<(std::ostream& out, const Board& g);


};

#endif 
