#ifndef Sword_H
#define Sword_H
#include "./symbol.h"

class Sword : public Symbol {
public:
	Sword();
	~Sword();
	std::string toString();
	void print();
protected:
private:
};

#endif