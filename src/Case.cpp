#include <iostream>
#include "Case.h"

Case::Case(CaseType type, int value) : m_value(value), m_type(type){

}

Case::~Case(){

}

CaseType Case::getType(){
	return m_type;
}

int Case::getValue(){
	return m_value;
}

void Case::setValue(int i){
	m_value = i;
}

void Case::draw(sf::RenderTarget* target, int size, int x, int y){
	sf::Font font;
	font.loadFromFile("fonts/verdana.ttf");

	sf::RectangleShape rectangle(sf::Vector2f(size, size));
	rectangle.setPosition(x, y);
	rectangle.setFillColor(sf::Color(235, 214, 177));
	rectangle.setOutlineThickness(2);
	rectangle.setOutlineColor(sf::Color(130, 113, 84));

	target->draw(rectangle);

	switch(m_type){

		case CaseType::INTEGER:

			// Mise en forme du texte
			sf::Text value;
			value.setFont(font);
			value.setString(std::to_string(m_value));
			value.setCharacterSize(30);
			value.setColor(sf::Color(130, 113, 84));
			value.setStyle(sf::Text::Bold);

			// Placement du texte 
			sf::FloatRect rect = value.getLocalBounds();
			value.setOrigin(rect.left + rect.width/2.0f, rect.top + rect.height/2.0f);
			value.setPosition( x + (size / 2), y + (size / 2));

			target->draw(value);
		break;
	}
}


std::ostream& operator<<(std::ostream& out, const Case& c){
	switch(c.m_type){
		case CaseType::EMPTY:
			out << " ";
		break;
		case CaseType::INTEGER:
			out << c.m_value;
		break;
		case CaseType::MULT_2:
			out << "x2";
		break;
		case CaseType::DIV_2:
			out << "/2";
		break;
		case CaseType::BOX:
			out << "O";
		break;
		case CaseType::WALL:
			out << "X";
		break;
	}
	
	return out;
}