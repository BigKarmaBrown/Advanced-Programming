#pragma once
#include "Player.h"
#include "Enemy.h"
using namespace std;
#include <iostream>
class Wizard : public Player
{	
protected:
	bool heavyAttackedUsed = false;
public:
	Wizard() : Player(40, 20) {};
	~Wizard();
	float attack(Player* player, Enemy* enemy) override;
	float attack(Player* player, Enemy* enemy, float Modifier) override;
	void takeTurn(Player* player, Enemy* enemy) override;
	bool run();
};
