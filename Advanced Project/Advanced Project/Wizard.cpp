#include "Wizard.h"

Wizard::~Wizard()
{
}
Wizard::Wizard()
{
}
Player::attack() override{
	srand(time(0)); 
	int randomNumber = rand() % 3 + 1;
}
