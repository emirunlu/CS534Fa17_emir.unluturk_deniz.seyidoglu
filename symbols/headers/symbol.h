#ifndef Symbol_H
#define Symbol_H
#include <string>
#include <iostream>

class Symbol {
public:
	virtual ~Symbol();
	virtual void print() = 0;
	virtual std::string toString() = 0;
protected:
private:
};

#endif