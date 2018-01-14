#ifndef NullCell_H
#define NullCell_H
#include "./cell.h"

class NullCell : public Cell {
public:
	NullCell();
	virtual ~NullCell();
	int getIndex();
	virtual Cell* searchOccupied(int currentIndex);
	virtual Cell* searchSymbol(Symbol* symbol, int currentIndex);
	virtual Symbol* getSymbol();
	virtual void setIndex(int i);
	virtual void print();
protected:
private:
	int index = 0;
};

#endif