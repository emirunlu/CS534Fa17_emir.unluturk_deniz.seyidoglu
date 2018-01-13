#ifndef Skull_H
#define Skull_H
#include "./symbol.h"

class Skull : public Symbol {
public:
	Skull();
	~Skull();
	std::string toString();
	void print();
protected:
private:
};

#endif