#pragma once
#include "Player.h"
#include "Enemy.h"
#include "GameState.h"
#include "NightCycle.h"
using namespace std;
class GameState;
#include <iostream>
class Barbarian : public Player
{
protected:
	bool heavyAttackedUsed = false;
	bool hitting = false;
public:
	Barbarian() : Player(15, 50, 50) {};
	~Barbarian();
	float attack(Player* player, Enemy* enemy) override;
	float attack(Player* player, Enemy* enemy, float Modifier) override;
	GameState::battleResult takeTurn(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle, Tree* tree) override;
	GameState::battleResult run(Player* player, GameState* gameState);
};
