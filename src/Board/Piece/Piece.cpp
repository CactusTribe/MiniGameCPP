#include <iostream>
#include "Piece.h"

Piece::Piece(PieceType type, int value) : _value(value), _type(type){

  sf::Texture texture;

  switch(_type){
    case PieceType::BOX:
      texture.loadFromFile("sprites/Crate_Purple.png");
      texture.setSmooth(true);
      _sprite.setTexture(texture);
      _sprite.setScale(sf::Vector2f(0.8f, 0.8f));
    break;

    case PieceType::WALL:
      texture.loadFromFile("sprites/WallRound_Brown.png");
      texture.setSmooth(true);
      _sprite.setTexture(texture);
      _sprite.setScale(sf::Vector2f(0.8f, 0.8f));
    break;

    case PieceType::END_POINT:
      texture.loadFromFile("sprites/EndPoint_Purple.png");
      texture.setSmooth(true);
      _sprite.setTexture(texture);
      _sprite.setScale(sf::Vector2f(0.8f, 0.8f));
    break;

    case PieceType::PLAYER_UP:
      texture.loadFromFile("sprites/Character7.png");
      texture.setSmooth(true);
      _sprite.setTexture(texture);
      _sprite.setScale(sf::Vector2f(0.8f, 0.8f));
    break;

    case PieceType::EMPTY:
      texture.loadFromFile("sprites/GroundGravel_Sand.png");
      texture.setSmooth(true);
      _sprite.setTexture(texture);
      _sprite.setScale(sf::Vector2f(0.8f, 0.8f));
    break;

    default:
      texture.loadFromFile("sprites/GroundGravel_Sand.png");
      texture.setSmooth(true);
      _sprite.setTexture(texture);
      _sprite.setScale(sf::Vector2f(0.8f, 0.8f));
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
  
  rectangle.setPosition(x, y);
  rectangle.setFillColor(sf::Color(235, 214, 177));
  rectangle.setOutlineThickness(2);
  rectangle.setOutlineColor(sf::Color(130, 113, 84));

  target->draw(rectangle);

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


  // Affichage du sprite
  _sprite.setPosition(x, y);
  target->draw(_sprite);

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
