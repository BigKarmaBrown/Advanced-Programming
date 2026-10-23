#include "Barbarian.h"



Barbarian::~Barbarian()
{
}
float Barbarian::attack(Enemy* enemy) {
	srand(time(0));
	int randomNumber = rand() % 2 + 1;
}