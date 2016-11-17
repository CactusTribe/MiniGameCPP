#include "GraphicsPiece.h"
#include <cstring>

GraphicsPiece::GraphicsPiece(PieceType type, const char* textureFile, const char* backgroundFile)
  : Piece(type)
{
  if(strlen(textureFile))
  {
    _background.loadFromFile(textureFile);
    _background.setSmooth(true);
  }

  if(strlen(backgroundFile))
  {
    _texture.loadFromFile(backgroundFile);
    _texture.setSmooth(true);
  }
}

GraphicsPiece::~GraphicsPiece()
{
}

void GraphicsPiece::draw(sf::RenderTarget* target) const
{
  if(!hasBoard())
    return;

  int size_x= target->getSize().x / board()->size();
  int size_y= target->getSize().y / board()->size();
  int pos_x= size_x * pos().x();
  int pos_y= size_y * pos().y();

  sf::Font font;
  font.loadFromFile("fonts/verdana.ttf");

  sf::RectangleShape rectangle(sf::Vector2f(size_x, size_y));
  sf::Text value;
  sf::FloatRect rect;

  // Affichage du background
  sf::Sprite sBackground;
  sBackground.setTexture(_background);
  rect = sBackground.getLocalBounds();
  double ratio_x = size_x / rect.width;
  double ratio_y = size_y / rect.height;
  sBackground.scale(sf::Vector2f(ratio_x, ratio_y));
  sBackground.setPosition(pos_x, pos_y);;
  target->draw(sBackground);

  rectangle.setPosition(pos_x, pos_y);
  rectangle.setFillColor(sf::Color(255, 255, 255, 0));
  rectangle.setOutlineThickness(2);
  rectangle.setOutlineColor(sf::Color(130, 113, 84));
  target->draw(rectangle);

/*
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
    break;*/

  sf::Sprite sTexture;
  sTexture.setTexture(_texture);
  rect = sTexture.getLocalBounds();
  sTexture.scale(sf::Vector2f(ratio_x, ratio_y));
  sTexture.setPosition(pos_x, pos_y);
  target->draw(sTexture);
}

