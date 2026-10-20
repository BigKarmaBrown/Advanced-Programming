#include "Archer.h"

Archer::Archer()
{
}

Archer::~Archer()
{
}
Player::attack() override {
	srand(time(0));
	int randomNumber = rand() % 5 + 1;
}