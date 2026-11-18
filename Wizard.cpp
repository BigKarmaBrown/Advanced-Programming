#include "Wizard.h"

Wizard::~Wizard()
{
}

float Wizard::attack(Player* player, Enemy* enemy)
{
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber = rand() % 2 + 1;
	if (randomNumber == 1)
	{
		damage = player->damage;
		enemy->takeDamage(player, damage);
		hitting = true;
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
		hitting = true;
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
		return 0;
	}
}

GameState::battleResult Wizard::takeTurn(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle, Tree* tree)
{
	string input;

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
		GameState::BattleMove* newMove = new GameState::BattleMove{
			 gameState->totalTurns + 1,"Wizard", "Attack",
			 hitting == true ? damage : 0
		};
		tree->battleHistory->Insert(newMove);
		hitting = false;
		gameState->totalTurns++;
		return GameState::battleResult::playerMidFight;
	}
	else if (input == "2" || input == "Heavy" || input == "2: Heavy Attack" || input == "H")
	{
		attack(player, enemy, 2);
		float damage = attack(player, enemy, 2);
		GameState::BattleMove* newMove = new GameState::BattleMove{
		 gameState->totalTurns + 1,"Wizard", "Heavy Attack",
		 hitting == true ? damage : 0
		};
		tree->battleHistory->Insert(newMove);
		hitting = false;
		gameState->totalTurns++;
		return GameState::battleResult::playerMidFight;
	}
	else if (input == "3" || input == "Brace" || input == "3: Brace" || input == "brace")
	{
		brace(enemy);
		GameState::BattleMove* newMove = new GameState::BattleMove{
		 gameState->totalTurns + 1,"Wizard", "Brace",0
		};
		tree->battleHistory->Insert(newMove);
		gameState->totalTurns++;
		return GameState::battleResult::playerMidFight;
	}
	else if (input == "4" || input == "Run" || input == "run" || input == "4: Run")
	{
		run(player, gameState);
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------- Wizard ran from the fight -------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		system("Pause");
		tree->battleHistory->~PriorityQueue();
		
		return GameState::battleResult::playerRan;
	}
	else {
		cout << "Invalid Input, Please try again!" << endl;
		gameState->totalTurns++;
		return GameState::battleResult::playerMidFight;
	}


}
GameState::battleResult  Wizard::run(Player* player, GameState* gameState) {
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------ Wizard Ran from Fight -------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	heavyAttackedUsed = false;
	health = maxHealth;
	gameState->playerRan;
	return GameState::battleResult::playerRan;
}
