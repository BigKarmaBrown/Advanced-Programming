#pragma once
#include "Player.h"
using namespace std;
#include <iostream>
class Barbarian : public Player
{
public:
	Barbarian() : Player(15, 50) {};
	~Barbarian();
	float attack(Enemy* enemy) override;
	void takeTurn();
};
