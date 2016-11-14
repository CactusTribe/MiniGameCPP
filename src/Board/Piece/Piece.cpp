#include <iostream>
#include "Piece.h"

Piece::Piece(PieceType type, int value) : _value(value), _type(type){

  _background.loadFromFile("sprites/GroundGravel_Sand.png");
  _background.setSmooth(true);

  switch(_type){
    case PieceType::BOX:
      _texture.loadFromFile("sprites/Crate_Purple.png");
      _texture.setSmooth(true);
    break;

    case PieceType::WALL:
      _texture.loadFromFile("sprites/WallRound_Brown.png");
      _texture.setSmooth(true);
    break;

    case PieceType::END_POINT:
      _texture.loadFromFile("sprites/EndPoint_Purple.png");
      _texture.setSmooth(true);
    break;

    case PieceType::PLAYER_UP:
      _texture.loadFromFile("sprites/Character7.png");
      _texture.setSmooth(true);
    break;

    case PieceType::EMPTY:
    break;

    default:
    break;
  }
  
}

Piece::~Piece(){

}

PieceType Piece::getType(){
  return _type;
}

int Piece::getValue(){
  return _value;
}

void Piece::setValue(int i){
  _value = i;
}

void Piece::draw(sf::RenderTarget* target, int size, int x, int y){
  sf::Font font;
  font.loadFromFile("fonts/verdana.ttf");

  sf::RectangleShape rectangle(sf::Vector2f(size, size));
  sf::Text value;
  sf::FloatRect rect;

  // Affichage du background
  sf::Sprite sprite;
  sprite.setTexture(_background);

  rect = sprite.getLocalBounds();
  double ratio_x = size / rect.width;
  double ratio_y = size / rect.height;
  sprite.scale(sf::Vector2f(ratio_x, ratio_y));
  sprite.setPosition(x, y);
  target->draw(sprite);

  rectangle.setPosition(x, y);
  rectangle.setFillColor(sf::Color(255, 255, 255, 0));
  rectangle.setOutlineThickness(2);
  rectangle.setOutlineColor(sf::Color(130, 113, 84));
  target->draw(rectangle);
  
  switch(_type){
    case PieceType::INTEGER:

      // Mise en forme du texte
      value.setFont(font);
      value.setString(std::to_string(_value));
      value.setCharacterSize(30);
      value.setColor(sf::Color(130, 113, 84));
      value.setStyle(sf::Text::Bold);

      // Placement du texte
      rect = value.getLocalBounds();
      value.setOrigin(rect.left + rect.width/2.0f, rect.top + rect.height/2.0f);
      value.setPosition( x + (size / 2), y + (size / 2));

      target->draw(value);
    break;

    default:
      // Affichage du sprite
      sf::Sprite sprite;
      sprite.setTexture(_texture);

      rect = sprite.getLocalBounds();
      double ratio_x = size / rect.width;
      double ratio_y = size / rect.height;
      sprite.scale(sf::Vector2f(ratio_x, ratio_y));
      sprite.setPosition(x, y);

      target->draw(sprite);
    break;
  }
}


std::ostream& operator<<(std::ostream& out, const Piece& c){
  switch(c._type){
    case PieceType::EMPTY:
      out << " ";
    break;
    case PieceType::INTEGER:
      out << c._value;
    break;
    case PieceType::MULT_2:
      out << "x2";
    break;
    case PieceType::DIV_2:
      out << "/2";
    break;
    case PieceType::BOX:
      out << "O";
    break;
    case PieceType::WALL:
      out << "X";
    break;
    case PieceType::PLAYER_UP:
    break;
    case PieceType::PLAYER_DOWN:
    break;
    case PieceType::PLAYER_LEFT:
    break;
    case PieceType::PLAYER_RIGHT:
    break;
    case PieceType::END_POINT:
    break;
  }
  return out;
}
