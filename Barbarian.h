#pragma once
#include "Player.h"
#include "Enemy.h"
using namespace std;
#include <iostream>
class Barbarian : public Player
{
public:
	Barbarian() : Player(15, 50) {};
	~Barbarian();
	float attack(Player* player, Enemy* enemy) override;
	void takeTurn(Player* player, Enemy* enemy);
	void const run();
};
