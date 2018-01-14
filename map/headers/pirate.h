#ifndef Pirate_H
#define Pirate_H
#include "../../map/headers/cell.h"

class Pirate {
public:
	Pirate(Cell* loc);
	~Pirate();
	void move(Cell* c);
	int getStatus();
	Cell* getCell();
	void print();
protected:
private:
	Cell* currentCell;
};

#endif