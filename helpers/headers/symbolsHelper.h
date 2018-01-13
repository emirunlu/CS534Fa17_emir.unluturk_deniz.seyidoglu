#ifndef SymbolHelper_H
#define SymbolHelper_H
#include "../../symbols/headers/bottle.h"
#include "../../symbols/headers/hat.h"
#include "../../symbols/headers/keys.h"
#include "../../symbols/headers/pistol.h"
#include "../../symbols/headers/skull.h"
#include "../../symbols/headers/sword.h"
#include "../../symbols/headers/symbol.h"

class SymbolHelper {
public:
	static Symbol* getRandomSymbol();
	static Symbol* getNewSymbol(int number);
protected:
private:
};

#endif