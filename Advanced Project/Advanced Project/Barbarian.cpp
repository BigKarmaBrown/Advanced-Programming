#include "Barbarian.h"

Barbarian::Barbarian()
{
}

Barbarian::~Barbarian()
{
}
Player::attack() override {
	srand(time(0));
	int randomNumber = rand() % 2 + 1;
}