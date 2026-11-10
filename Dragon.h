#pragma once
#include "Enemy.h"
#include "NightCycle.h"
using namespace std;
#include <iostream>
class Dragon : public Enemy
{
public:
	Dragon();
	~Dragon();
	float attack(float damage, Player* player, NightCycle* cycle) override;
	void displayPicture() override;
};