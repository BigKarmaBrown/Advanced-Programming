#include "GameState.h"
using namespace std;
#include <iostream>

void GameState::GameStart(Player* player, Enemy* enemy)
{
	srand(time(0));
	int whosTurn = rand() % 2 + 1;
	do {
		if (whosTurn == 1)
		{
			player->attack(enemy);
			whosTurn == 2;
		}

		if (whosTurn == 2)
		{
			enemy->taketurn(enemy, player);
			whosTurn == 1;
		}

		//fighting will be here


		

	}
	while (player->health > 0 && enemy->health > 0);
}