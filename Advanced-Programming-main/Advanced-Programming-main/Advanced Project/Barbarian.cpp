#include "Barbarian.h"

Barbarian::Barbarian()
{
}

Barbarian::~Barbarian()
{
}
int Barbarian::attack(Enemy* enemy) override {
	srand(time(0));
	int randomNumber = rand() % 2 + 1;
}