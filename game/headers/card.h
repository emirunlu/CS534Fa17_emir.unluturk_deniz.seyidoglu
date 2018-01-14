#ifndef Card_H
#define Card_H
#include "../../symbols/headers/symbol.h"

class Card {
public:
	Card();
	Card(int symbol);
	virtual ~Card();
	virtual Symbol* getSymbol();
	virtual void print();
protected:
private:
	Symbol* symbol;
};

#endif