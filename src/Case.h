#ifndef CASE_H
#define CASE_H

#include "CaseType.h"

class Case{
public:
	Case(CaseType type, int value);
	~Case();

private:
	int m_value = 0;
	CaseType m_type;

friend std::ostream& operator<<(std::ostream& out, const Case& c);
};

#endif 