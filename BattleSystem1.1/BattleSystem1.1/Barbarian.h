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
	float attack(Enemy* enemy) override;
	void takeTurn(Enemy* enemy);
};
