#pragma once
#include "Player.h"
#include "Enemy.h"
#include "GameState.h"

using namespace std;
#include <iostream>
class Wizard : public Player
{	
protected:
	bool heavyAttackedUsed = false;
public:
	Wizard() : Player(40, 30) {};
	~Wizard();
	float attack(Player* player, Enemy* enemy) override;
	float attack(Player* player, Enemy* enemy, float Modifier) override;
	battleResult takeTurn(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle) override;
	battleResult run();
};
