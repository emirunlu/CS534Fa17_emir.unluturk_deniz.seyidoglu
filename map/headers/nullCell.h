#ifndef NullCell_H
#define NullCell_H
#include "./cell.h"

class NullCell : public Cell {
public:
	NullCell();
	virtual ~NullCell();
	virtual void print();
protected:
private:
	int index = 0;
};

#endif