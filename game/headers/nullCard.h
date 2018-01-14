#ifndef NullCard_H
#define NullCard_H
#include <iostream>
#include "./card.h"

class NullCard : public Card {
public:
	NullCard();
	NullCard(int symbol);
	virtual ~NullCard();
	virtual Symbol* getSymbol();
	virtual void print();
protected:
private:
};

#endif