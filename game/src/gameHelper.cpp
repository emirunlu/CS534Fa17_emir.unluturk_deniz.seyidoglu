#include "../headers/gameHelper.h"
#include "../headers/player.h"

GameHelper::GameHelper() {
	player = new Player();
	currentPlayer = player;
}

GameHelper::GameHelper(std::string name)
{
	player = new Player(name);
	currentPlayer = player;
}

GameHelper::~GameHelper()
{
}

void
GameHelper::addPlayer(std::string name)
{
	Player* p = new Player(name);
	Players.push_back(p);
}

void
GameHelper::setPlayer(Player * p)
{
	player = p;
}

void
GameHelper::updatePlayerTurn(int turn)
{
	if (turn == 1)
		currentPlayer = player;
	else {
		int t = turn - 2;
		for (unsigned int i = 0; i < Players.size(); ++i) {
			if (t == i)
				currentPlayer = Players.at(i);
		}
	}
}

Player*
GameHelper::getCurrentPlayer()
{
	return currentPlayer;
}

vector<Player*>
GameHelper::getPlayers() {

	vector<Player*> c;
	for (unsigned int i = 0; i < Players.size(); ++i) {
		Player* p = Players.at(i);
		c.push_back(p);
	}
	return c;
}

void
GameHelper::setPlayerTurn(Player * p)
{
	currentPlayer = p;
}