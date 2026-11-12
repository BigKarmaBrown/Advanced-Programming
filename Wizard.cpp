#include "Wizard.h"

Wizard::~Wizard()
{
}

float Wizard::attack(Player* player,Enemy* enemy) 
{
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand() % 2 + 1;
	if (randomNumber == 1)
	{
		damage = player->damage;
		enemy->takeDamage(player, damage);
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Attack Hit For " << damage << "------------------------------------------------------- " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		heavyAttackedUsed = false;
		return damage;
	}
	else
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Attack Missed -------------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		heavyAttackedUsed = false;
		return false;
	}
}
float Wizard::attack(Player* player,Enemy* enemy, float Modifier) 
{
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand() % 3 + 1;
	if (heavyAttackedUsed == true) {
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "---------------------------------------------- Heavy Attack On Cooldown ------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return 0;
	}
	if (randomNumber == 1)
	{
		float damageTotal = player->damage * Modifier;
		enemy->takeDamage(player, damageTotal);
		heavyAttackedUsed = true;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Attack Hit For " << damageTotal << "------------------------------------------------------- " << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return damageTotal;
	}
	else
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Attack Missed -------------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		return false;
	}
}

battleResult Wizard::takeTurn(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle)
{
	string input;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------- Players Turn ------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl   << endl << endl;
	cout << "Health: " << player->health << endl;
	cout << "Damage: " << player->damage << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "1: Attack" << endl;
	cout << "2: Heavy Attack" << endl;
	cout << "3: Brace" << endl;
	cout << "4: Run" << endl;

	cin >> input;

	if (input == "1" || input == "Attack" || input == "1: Attack" || input == "attack")
	{
		attack(player, enemy);
		
		return battleResult::playerMidFight;
	}
	else if (input == "2" || input == "Heavy" || input == "2: Heavy Attack" || input == "H")
	{
		attack(player, enemy);
		
		return battleResult::playerMidFight;
	}
	else if (input == "3" || input == "Brace" || input == "3: Brace" || input == "brace")
	{
		brace(enemy);
		return battleResult::playerMidFight;
	}
	else if (input == "4" || input == "Run" || input == "run" || input == "4: Run")
	{
		run();
		return battleResult::playerRan;
	}
	else {
		cout << "Invalid Input, Please try again!" << endl;
		return battleResult::playerMidFight;
	}


}
battleResult  Wizard::run() {
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------ Wizard Ran from Fight -------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	heavyAttackedUsed = false;
	health = maxHealth;
	return battleResult::playerRan;
}
