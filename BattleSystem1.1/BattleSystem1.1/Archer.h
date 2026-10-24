#pragma once
#include "Player.h"
using namespace std;
#include <iostream>
class Archer : public Player
{
public:

	Archer() : Player(30, 30) {};
	~Archer();
	float attack(Enemy* enemy) override;
	void takeTurn();
};
