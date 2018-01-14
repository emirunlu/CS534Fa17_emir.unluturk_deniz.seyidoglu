#include "../headers/imageManager.h"

imageManager::imageManager(SDL_Surface* screenSurface) {
	this->screenSurface = screenSurface;
}

imageManager::~imageManager() {

}


SDL_Surface*
imageManager::loadPNG(std::string path) {
	SDL_Surface* pngFile = NULL;

	SDL_Surface* load = IMG_Load(path.c_str());
	if (load == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		pngFile = SDL_ConvertSurface(load, screenSurface->format, NULL);
		if (pngFile == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(load);
	}

	return pngFile;
}

void
imageManager::drawBackground(SDL_Surface* bgImage) {
	SDL_Rect source = { 0, 0, 800, 600 };
	SDL_Rect destination = { 0, 0, 800, 600 };

	SDL_BlitSurface(bgImage, &source, screenSurface, &destination);
}