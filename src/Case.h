#ifndef CASE_H
#define CASE_H

#include <SFML/Graphics.hpp>
#include "CaseType.h"

class Case{
public:
	Case(CaseType type, int value);
	~Case();

	CaseType getType();
	int getValue();
	void setValue(int i);
	void draw(sf::RenderTarget* target, int size, int x, int y);

private:
	int m_value = 0;
	CaseType m_type;

friend std::ostream& operator<<(std::ostream& out, const Case& c);
};

#endif 