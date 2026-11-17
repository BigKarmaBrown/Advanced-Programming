#pragma once
#include "Player.h"
#include "Enemy.h"
#include "GameState.h"

//using namespace std;
#include <iostream>
class Wizard : public Player
{	
protected:
	bool heavyAttackedUsed = false;
	bool hitting = false;
public:
	Wizard() : Player(40, 30, 30) {};
	~Wizard();
	float attack(Player* player, Enemy* enemy) override;
	float attack(Player* player, Enemy* enemy, float Modifier) override;
	GameState::battleResult takeTurn(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle, Tree* tree) override;
	GameState::battleResult run(Player* player, GameState* gameState);
};
