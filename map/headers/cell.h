#ifndef Cell_H
#define Cell_H
#include "../../symbols/headers/symbol.h"

class Cell {
public:
	Cell();
	Cell(int symbolNumber);
	virtual ~Cell();
	void setSymbolCell(Symbol* sym);
	void setIndex(int i);
	virtual void print();
protected:
private:
	Symbol* symbol;
	int index;
};

#endif