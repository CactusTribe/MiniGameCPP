#ifndef SokobanEmptyPiece_H
#define SokobanEmptyPiece_H

#include "../../Shared/Board/Piece/GraphicsPiece.h"

class SokobanEmptyPiece : public GraphicsPiece {

  public:
    SokobanEmptyPiece()
      : GraphicsPiece(PieceType::Empty ,"sprites/GroundGravel_Sand.png", "")
    {}

    virtual ~SokobanEmptyPiece()
    {}

};

class SokobanBoxPiece : public GraphicsPiece {

  public:
    SokobanBoxPiece()
  : GraphicsPiece(PieceType::Box ,"sprites/GroundGravel_Sand.png", "sprites/Crate_Purple.png")
  {;}
    virtual ~SokobanBoxPiece(){};

    private:
      Piece* previousPiece;
};

class SokobanWallPiece : public GraphicsPiece {

  public:
    SokobanWallPiece()
  : GraphicsPiece(PieceType::Wall ,"sprites/GroundGravel_Sand.png", "sprites/WallRound_Brown.png")
  {;}
    virtual ~SokobanWallPiece(){};

    virtual bool canMovedBy(const Board* board, Piece* source, Pos2D src) const
    {
      return false;
    }
};

class SokobanEndPointPiece : public GraphicsPiece {

  public:
    SokobanEndPointPiece()
  : GraphicsPiece(PieceType::EndPoint ,"sprites/GroundGravel_Sand.png", "sprites/EndPoint_Purple.png")
  {;}
    virtual ~SokobanEndPointPiece(){};

};

class SokobanPlayerPiece : public GraphicsPiece {

  public:
    SokobanPlayerPiece()
  : GraphicsPiece(PieceType::Player,"sprites/GroundGravel_Sand.png", "sprites/PlayerDown.png")
  {;}

    Piece * _store= nullptr;

    virtual ~SokobanPlayerPiece(){};

    virtual bool onMovedTo(Board* board, Piece* target, Pos2D dst)
    {
      board->push(_store, pos());
      _store= board->get(dst);

      Pos2D dir= pos() - dst;

      if( dir ==  Direction::one_up)
        _texture.loadFromFile("sprites/PlayerUp.png");
      if( dir ==  Direction::one_down)
        _texture.loadFromFile("sprites/PlayerDown.png");
      if( dir ==  Direction::one_left)
        _texture.loadFromFile("sprites/PlayerLeft.png");
      if( dir ==  Direction::one_right)
        _texture.loadFromFile("sprites/PlayerRight.png");

      return false;
    }
};
#endif
