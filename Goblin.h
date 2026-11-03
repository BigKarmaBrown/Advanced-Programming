#pragma once
#include "Enemy.h"
using namespace std;
#include <iostream>
class Goblin : public Enemy
{
public:
	Goblin();
	~Goblin();
	float attack(float damage, bool hit, Player* player) override;
};
