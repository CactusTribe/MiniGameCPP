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