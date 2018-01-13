#ifndef Bottle_H
#define Bottle_H
#include "./symbol.h"

class Bottle : public Symbol {
public:
	Bottle();
	~Bottle();
	std::string toString();
	void print();
protected:
private:
};

#endif