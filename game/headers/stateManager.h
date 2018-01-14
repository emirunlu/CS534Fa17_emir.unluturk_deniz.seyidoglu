#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <iostream>
#include <vector>
#include "state.h"

class stateManager {
public:
	static void setState(State* state);

	static State* getState();

private:
	static std::vector<State*> states;
};

#endif