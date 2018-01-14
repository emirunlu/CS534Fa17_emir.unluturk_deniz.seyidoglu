#ifndef GAME_STATE_H
#define GAME_STATE_H

#include<SDL.h>
#include "state.h"
#include "stateManager.h"

class gameState : public State
{
public:
	void Init();
	void handleEvents(SDL_Event& event);
	void Update();
	void Render();
	void clean();
};

#endif