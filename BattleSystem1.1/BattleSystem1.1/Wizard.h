#pragma once
#include "Player.h"
using namespace std;
#include <iostream>
class Wizard : public Player
{
public:
	Wizard() : Player(40) {};
	~Wizard();
	float attack(Enemy* enemy) override;
};
