#pragma once
using namespace std;
#include "Player.h"
#include "Barbarian.h"
#include "Wizard.h"
#include "Archer.h"
#include "Enemy.h"
#include "Dragon.h"
#include "Goblin.h"


class Menu
{
public:
	void StartMenu();
	void characterSelection(Player* player);
	void chooseOpponent(Enemy* enemy);
};

