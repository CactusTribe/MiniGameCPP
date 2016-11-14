#include <iostream>
#include "Board.h"
#include "Piece/PieceType.h"

Board::Board(int size) : m_size(size), m_matrice(size, std::vector<Piece>(size, Piece(PieceType::EMPTY, 0))){

}

Board::~Board(){

}

Piece Board::get(int x, int y){
  return m_matrice[y][x];
}

int Board::getSize(){
  return m_size;
}

bool Board::changePiece(Piece c, int x, int y){
  if(x < m_size && y < m_size){
    m_matrice[y][x] = c;

    return true;
  }
  else{
    return false;
  }
}

std::ostream& operator<<(std::ostream& out, const Board& g){

  out << std::endl;

  for(int i=0; i < g.m_size ; i++){

    for(int k=0; k < g.m_size ; k++){
      out << "----";
    }
    out << std::endl;

    out << "|";

    for(int j=0; j < g.m_size ; j++){
      out << " " << g.m_matrice[j][i] << " |";
    }
    out << std::endl;
  }

    for(int k=0; k < g.m_size ; k++){
      out << "----";
    }
    out << std::endl;

  return out;
}

void Board::draw(IHM& render)
{
  int case_size = render.window_size() / getSize();
  // Affichage de la grille
  for(int i=0; i < getSize(); i++){
    for(int j=0; j < getSize(); j++){
      get(j,i).draw(render.app(), case_size, j*case_size, i*case_size);
    }
  }
}
