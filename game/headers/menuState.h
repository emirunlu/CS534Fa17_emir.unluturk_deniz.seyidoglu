#ifndef MENU_STATE_H
#define MENU_STATE_H

#include<SDL.h>
#include "state.h"
#include "stateManager.h"

class menuState : public State
{
public:
	void Init();
	void handleEvents(SDL_Event& event);
	void Update();
	void Render();
	void clean();
};

#endif