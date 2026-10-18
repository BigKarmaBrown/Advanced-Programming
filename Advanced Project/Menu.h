#pragma once
using namespace std;
#include "Player.h"
#include "Barbarian.h"
#include "Wizard.h"
#include "Archer.h"


class Menu
{
public:
	void StartMenu();
	void characterSelection(Player* player);
};

