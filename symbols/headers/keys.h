#ifndef Keys_H
#define Keys_H
#include "./symbol.h"

class Keys : public Symbol {
public:
	Keys();
	~Keys();
	std::string toString();
	void print();
protected:
private:
};

#endif