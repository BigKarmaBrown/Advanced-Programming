#pragma once
#include "GameState.h"
#include "Menu.h"
#include "ErrorHandler.h"
#include "assert.h"
#include "NightCycle.h"
using namespace std;
#include <iostream>


GameState::battleResult GameState::GameStart(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle, LinkedListMoves* moves)
{
	system("CLS");
	srand(static_cast<unsigned int>(time(0)));
	int whosTurn = rand() % 2 + 1;
	//battleResult::playerMidFight;

	void (*showTurns)(int);
	showTurns = &GameState::showTurn;
	//Declare a pointer of return type void 
	// and state that the function needs type int.
	// Assign the function to a memory address. 

	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "---------------------------------------------------- BATTLE HAS STARTED ------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	system("Pause");
	system("CLS");
	enemy->displayPicture();
	while (true){
		if (playerRanBool == true) {
			return battleResult::playerRan;
		}
		
		if (player->health <= 0 || enemy->health <= 0) {
			try {
				displayWinner(player, enemy, moves);
			if (player->health <= 0) {
				return battleResult::playerLose;
			}

			return battleResult::playerWin;
				
			}
			catch(ErrorHandler e)
			{
				cout << "Exception: " << e.cantDisplayWInner();
			
			}//Try keyword is used to attempt the preceding code. 
			//If it cannot, it outputs the catch statement, 
			//which is calling on the error message rather than crashing. 
			
			
		}
		else if (whosTurn == 1)
		{
			 auto turn = player->takeTurn(player, enemy, gameState, cycle, moves);
			 AccountTurns++;
			 if (playerRanBool == true) {
				 return battleResult::playerRan;
			 }
			 if (turn == battleResult::playerRan) {
				 return battleResult::playerRan;
			 }
			system("Pause");
			system("CLS");
			enemy->displayPicture();
			whosTurn = 2;
			showTurns(whosTurn);
			//Assign/ Calculate a variable 
			// which is passed into the pointers function call.
		}
	
		else if (whosTurn == 2) {
			enemy->taketurn(enemy, player, cycle, gameState, moves);
			AccountTurns++;
			system("Pause");
			system("CLS");
			enemy->displayPicture();
			whosTurn = 1;
			showTurns(whosTurn);
			
		}
		else {
			//throw(...); 

			
		}
	
	}

}

void GameState::displayWinner(Player* player, Enemy* enemy, LinkedListMoves* moves) {
	if (enemy->health <= 0)
	{
		player->killed++;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "------------------------------------------------------You Won The Fight-------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

		system("Pause");

		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "----------------------------------------------- Health increased by 10 -------------------------------------------------" << endl;
		cout << "----------------------------------------------- Damage increased by 10 -------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

		player->damage += 10;
		player->maxHealth += 10;
		displayDead(player);
		DisplayBattleHistory(moves);
		system("Pause");
		//delete enemy;
	
		return;
	}
	else if (player->health <= 0)
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "---------------------------------------------------- You Lost The Fight ------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		 
		system("Pause");

		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-------------------------------------------------------- GAME OVER -----------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

		displayDead(player);
		//delete player;
		DisplayBattleHistory(moves);
		system("Pause");
		
		return;
	}
}

void GameState::displayDead(Player* player)
{
	
	cout << "Enemies Slain: " << player->killed << endl;
	//The other class can access private data via friendship.
}

 void GameState:: showTurn(int turn)
{
 try {
		if (turn == 1) {
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "--------------------------------------------------------- Players Turn -------------------------------------------------" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			}
			else if (turn == 2) {
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			cout << "--------------------------------------------------------- Enemys Turn --------------------------------------------------" << endl;
			cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
			}
			else 
			{
			cout << "whos turn is it?" << endl;
			}
	}
	 catch (ErrorHandler e) {
		 e.cantAcknowledgeTurn();
	 }
}

 void GameState::DisplayBattleHistory(LinkedListMoves* moves)
 {
	 system("Pause");
	 system("CLS");
	 cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	 cout << "-------------------------------------------------------- Battle History ------------------------------------------------" << endl;
	 cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

	 //while (moves->battleHistory->Size() > 0) {
	
		// BattleMove* move = moves->battleHistory->Remove();
	 //
		// cout << "Turn Number: " << move->turnNum << endl;
		// cout << endl;
		//cout << "Person: " << move->person << endl;
		//cout << "Move: " << move->move << endl;
		// if (move->damage > 0) {
		//cout << "Damage: " << move->damage << endl;
		// }
		// cout << endl << endl;

	 //delete move;


	 //}
	
	
 }

 GameState::GameState(LinkedListMoves* moves)
 {
	// moves->
	 //moves->battleHistory = moves->battleHistory;
 }


