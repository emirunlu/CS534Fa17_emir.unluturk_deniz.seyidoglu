#ifndef Card_H
#define Card_H
#include "../../symbols/headers/symbol.h"


class Card {
public:
	Card();
	Card(int symbol);
	~Card();
	Symbol* getSymbol();
	void print();
protected:
private:
	Symbol* symbol;
};

#endif