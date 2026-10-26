#include "Wizard.h"

Wizard::~Wizard()
{
}

float Wizard::attack(Enemy* enemy) 
{
	srand(time(0));
	int randomNumber = rand() % 3 + 1;
	if (randomNumber == 1)
	{
		return damage;
	}
	else
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Attack Missed -------------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}

void Wizard::takeTurn(Enemy* enemy)
{
	string input;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------- Players Turn ------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "1: Attack" << endl;
	cout << "2: Brace" << endl;
	cout << "3: Run" << endl;

	cin >> input;

	if (input == "1" || input == "Attack" || input == "1: Attack" || input == "attack")
	{
		float damage = attack(enemy);
		enemy->takeDamage(damage);
	}
	else if (input == "2" || input == "Brace" || input == "2: Brace" || input == "brace")
	{

	}
	else if (input == "3" || input == "Run" || input == "run" || input == "3: Run")
	{

	}
	else {
		cout << "Invalid Input, Please try again!" << endl;
		return;
	}


}
