#ifndef Boat_H
#define Boat_H
#include "./cell.h"

class Boat : public Cell {
public:
	Boat();
	~Boat();
	virtual void print();
protected:
private:
	int index = 37;
};

#endif