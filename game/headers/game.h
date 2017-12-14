#ifndef Game_H
#define Game_H
#include "../../map/headers/segment.h"
#include "./map.h"
#include "./card.h"

class Game {
public:
	Game();
	~Game();
	Map* getMap();
	std::vector<Card*> getCards();
protected:
private:
	std::vector<Card*> cards;
	Map* map;
};

#endif