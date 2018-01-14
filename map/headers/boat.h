#ifndef Boat_H
#define Boat_H
#include "./cell.h"

class Boat : public Cell {
public:
	Boat();
	~Boat();
	virtual Cell* searchOccupied(int currentIndex);
	virtual Cell* searchSymbol(Symbol* symbol, int currentIndex);
	int getIndex();
	virtual Symbol* getSymbol();
	virtual void setIndex(int i);
	virtual void print();
protected:
private:
	int index;
};

#endif