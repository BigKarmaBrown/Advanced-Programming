#include "Enemy.h"
#include "Player.h"
using namespace std;
#include <iostream>
class GameState
{
	int totalTurns;
	bool playersTurn;

protected:
	void GameStart(Player* player, Enemy* enemy);

};
