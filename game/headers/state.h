#ifndef STATE_H
#define STATE_H

#include<SDL.h>

class State
{
public:
	virtual void Init() = 0;
	virtual void handleEvents(SDL_Event& event) = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;

	virtual void clean() = 0;
};
#endif