#ifndef Card_H
#define Card_H
#include "../../symbols/headers/symbol.h"

class Card {
public:
	Card();
	~Card();
	Symbol* getSymbol();
protected:
private:
	Symbol* symbol;
};

#endif