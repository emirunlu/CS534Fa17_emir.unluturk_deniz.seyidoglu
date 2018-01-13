#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include "../headers/game.h"


using namespace std;

Game::Game() {
	for (int i = 0; i < 30; ++i) {
		for (int j = 0; j < 6; ++j){
			cards.push_back(new Card(j));
		}
	}
  	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  	shuffle (cards.begin(), cards.end(), std::default_random_engine(seed));

  	map = new Map();
}

Game::~Game() {
	for (int i = 0; i < cards.size(); ++i) {
		delete cards[i];
	}
	cards.clear();
	delete map;
}

Map*
Game::getMap() {
	return map;
}

std::vector<Card*>
Game::getCards(int num) {
	std::vector<Card*> playerCards;
	if (cards.size() > 0) {
		for (int i = 0; i < num; ++i){
			playerCards.push_back(cards[i]);
			cards.erase(cards.begin() + i);
		}
		return playerCards;
	} else {
		cout << "No more cards!" << endl;
	}
}

Card* 
Game::getCard() {
	if (cards.size() > 0) {
		Card* card = cards[0];
		cards.erase(cards.begin());
		return card;
	} else {
		cout << "No more cards!" << endl;
	}
}

void
Game::clearCards() {
	cards.clear();
}