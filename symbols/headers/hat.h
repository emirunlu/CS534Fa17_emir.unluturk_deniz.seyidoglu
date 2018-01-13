#ifndef Hat_H
#define Hat_H
#include "./symbol.h"

class Hat : public Symbol {
public:
	Hat();
	~Hat();
	std::string toString();
	void print();
protected:
private:
};

#endif