#ifndef Pistol_H
#define Pistol_H
#include "./symbol.h"

class Pistol : public Symbol {
public:
	Pistol();
	~Pistol();
	std::string toString();
	void print();
protected:
private:
};

#endif