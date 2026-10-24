#pragma once
using namespace std;
#include "Player.h"
#include "Barbarian.h"
#include "Wizard.h"
#include "Archer.h"
#include "Enemy.h"
#include "Dragon.h"
#include "Goblin.h"
#include "Gamestate.h"


class Menu
{
public:
	void StartMenu(Player*& player, Enemy*& enemy, GameState* gameState);
	void characterSelection(Player* player, Enemy* enemy, GameState* gameState);
	void chooseOpponent(Player* player, Enemy* enemy, GameState* gameState);
};
