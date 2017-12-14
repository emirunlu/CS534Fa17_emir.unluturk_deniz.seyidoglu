#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>

#include "../headers/game.h"
#include "../../helpers/headers/symbolsHelper.h"

using namespace std;

Game::Game() {
	// Cards
	for (int i = 0; i < 30; ++i) {
		for (int j = 0; j < 6; ++j){
			cards.push_back(new Card(j));
		}
	}
  	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  	shuffle (cards.begin(), cards.end(), std::default_random_engine(seed));

  	// Map
  	map = new Map();
}

Game::~Game() {
	
}

Map*
Game::getMap() {
	return map;
}

std::vector<Card*>
Game::getCards() {
	return cards;
}