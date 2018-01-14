#ifndef Game_H
#define Game_H
#include "../../map/headers/segment.h"
#include "./map.h"
#include "./card.h"
#include "./nullCard.h"

class Game {
public:
	Game();
	~Game();
	Map* getMap();
	void shuffleOldCards();
	std::vector<Card*> getCards(int num);
	Card* getCard();
	void clearCards();
protected:
private:
	std::vector<Card*> cards;
	std::vector<Card*> usedCards;
	Map* map;
};

#endif