#include "Wizard.h"

Wizard::~Wizard()
{
}

float Wizard::attack(Player* player, Enemy* enemy)
{
	//Using the same function name but passing different parameters, 
	// gives separate implementations called via the parameters.
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

GameState::battleResult Wizard::takeTurn(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle, LinkedListMoves* moves)
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
		//The functions are both called via attack but different parameters,
		// therefore different definitions and uses.
		battleMove* newMove = new battleMove{
			 gameState->totalTurns + 1,"Wizard", "Attack",
			 hitting == true ? damage : 0
		};
		Link* link = new Link(newMove);
		moves->Insert(link);
		//tree->battleHistory->Insert(newMove);
		hitting = false;
		gameState->totalTurns++;
		return GameState::battleResult::playerMidFight;
	}
	else if (input == "2" || input == "Heavy" || input == "2: Heavy Attack" || input == "H")
	{
		attack(player, enemy, 2);
		float damage = attack(player, enemy, 2);
		battleMove* newMove = new battleMove{
		 gameState->totalTurns + 1,"Wizard", "Heavy Attack",
		 hitting == true ? damage : 0
		};
		Link* link = new Link(newMove);
		moves->Insert(link);
	//	tree->battleHistory->Insert(newMove);
		//tree->Insert(*newMove, newMove->turnNum);
		hitting = false;
		gameState->totalTurns++;
		return GameState::battleResult::playerMidFight;
	}
	else if (input == "3" || input == "Brace" || input == "3: Brace" || input == "brace")
	{
		brace(enemy);
		battleMove* newMove = new battleMove{
		 gameState->totalTurns + 1,"Wizard", "Brace",0
		};
		Link* link = new Link(newMove);
		moves->Insert(link);
		//tree->battleHistory->Insert(newMove);
		//tree->Insert(*newMove, newMove->turnNum);
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
		//tree->battleHistory->~PriorityQueue();
		moves->~LinkedListMoves();
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
