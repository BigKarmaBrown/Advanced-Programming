#pragma once
#include "Player.h"
#include "Enemy.h"
using namespace std;
#include <iostream>
class Archer : public Player
{
public:

	Archer() : Player(30, 30) {};
	~Archer();
	float attack(Enemy* enemy) override;
	void takeTurn(Enemy* enemy);
	void const run();
};
