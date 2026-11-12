#pragma once
using namespace std;
#include "Player.h"
#include "Barbarian.h"
#include "Wizard.h"
#include "Archer.h"
#include "Enemy.h"
#include "Dragon.h"
#include "Goblin.h"
#include "GameState.h"
#include "NightCycle.h"


class Menu
{
public:
	void StartMenu(Player*& player, Enemy*& enemy, GameState* gameState, NightCycle* cycle);
	void characterSelection(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle);
	void chooseOpponent(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle);
};
