#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H

#include <SDL.h>
#include <SDL_image.h>

#include <string>
#include <vector>

class imageManager {
public:
	imageManager(SDL_Surface*);
	~imageManager();
	SDL_Surface * loadPNG(std::string path);
	void drawBackground(SDL_Surface * bgImage);
private:
	SDL_Surface * screenSurface;
};

#endif