#ifndef Helper_H
#define Helper_H

#include "./bottle.h"
#include "./hat.h"
#include "./keys.h"
#include "./pistol.h"
#include "./skull.h"
#include "./sword.h"
#include "./symbol.h"

class Helper {
public:
	static Symbol* getRandomSymbol();
	static Symbol* getNewSymbol(int number);
protected:
private:
};

#endif