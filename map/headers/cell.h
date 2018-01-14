#ifndef Cell_H
#define Cell_H
#include "../../symbols/headers/symbol.h"

class Cell {
public:
	Cell();
	Cell(int symbolNumber);
	virtual ~Cell();
	void setSymbolCell(Symbol* sym);
	virtual void setIndex(int i);
	int getIndex();
	int getOccupied();
	void decreaseOccupied();
	virtual Cell* searchOccupied(int currentIndex);
	virtual Cell* searchSymbol(Symbol* symbol, int currentIndex);
	virtual Symbol* getSymbol();
	virtual void print();
protected:
private:
	Symbol* symbol;
	int index;
	int occupied;
};

#endif