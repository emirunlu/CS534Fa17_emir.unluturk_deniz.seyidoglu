#include "../headers/stateManager.h"

std::vector<State*> stateManager::states;

void 
stateManager::setState(State* state) {
	if (!states.empty()) {

		states.back()->clean();

		delete states.back();
		states.back() = NULL;

		states.pop_back();
	}
	states.push_back(state);
	states.back()->Init();
}

State* 
stateManager::getState() {
	return states.back();
}