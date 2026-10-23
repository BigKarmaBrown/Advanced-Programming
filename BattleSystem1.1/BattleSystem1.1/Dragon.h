#pragma once
#include "Enemy.h"
using namespace std;
#include <iostream>
class Dragon : public Enemy
{
public:
	Dragon();
	~Dragon();
	float attack(float damage, bool hit, Player* player) override;
};