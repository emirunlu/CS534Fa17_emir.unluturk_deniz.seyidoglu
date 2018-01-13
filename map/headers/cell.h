#ifndef Cell_H
#define Cell_H
#include "../../symbols/headers/symbol.h"

class Cell {
public:
	Cell();
	Cell(int symbolNumber);
	virtual ~Cell();
	void setSymbolCell(Symbol* sym);
	void setOccupied(bool cond);
	void setIndex(int i);
	int getIndex();
	virtual Cell* searchSymbol(Symbol* symbol);
	virtual void print();
protected:
private:
	Symbol* symbol;
	int index;
	bool occupied;
};

#endif