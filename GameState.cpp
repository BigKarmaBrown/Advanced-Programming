#pragma once
#include "GameState.h"
#include "Menu.h"
#include "ErrorHandler.h"
#include "assert.h"
#include "NightCycle.h"
using namespace std;
#include <iostream>


GameState::battleResult GameState::GameStart(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle)
{
	system("CLS");
	srand(static_cast<unsigned int>(time(0)));
	int whosTurn = rand() % 2 + 1;
	//battleResult::playerMidFight;

	void (*showTurns)(int);
	showTurns = &GameState::showTurn;
	

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
				displayWinner(player, enemy);
			if (player->health <= 0) {
				return battleResult::playerLose;
			}
			return battleResult::playerWin;
				
			}
			catch(ErrorHandler e)
			{
				cout << "Exception: " << e.cantDisplayWInner();
			
			}
			
			
		}
		else if (whosTurn == 1)
		{
			 auto turn = player->takeTurn(player, enemy, gameState, cycle);
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
		}
	
		else if (whosTurn == 2) {
			enemy->taketurn(enemy, player, cycle);
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

void GameState::displayWinner(Player* player, Enemy* enemy) {
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
		player->health += 10;
		displayDead(player);
		delete enemy;
	
		return;
	}
	else if (player->health <= 0)
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-----------------------------------------------------You Lost The Fight-------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		 
		system("Pause");

		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "------------------------------------------------------ GAME OVER -------------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

		displayDead(player);
		delete player;
		
		return;
	}
}

void GameState::displayDead(Player* player)
{
	//assert(player->killed);
	cout << "Enemies Slain: " << player->killed << endl;
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

 void GameState::DisplayBattleHistory()
 {
	 cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	 cout << "-------------------------------------------------------- Battle History ------------------------------------------------" << endl;
	 cout << "------------------------------------------------------------------------------------------------------------------------" << endl;

	 while (battleHistory->Size() > 0) {
	
		 BattleMove* move = battleHistory->Remove();
	 
		 cout << "Turn Number: " << move->turnNum << endl;
		cout << "Person: " << move->person << endl;
		cout << "Move: " << move->move << endl;
		 if (move->damage > 0) {
		cout << "Damage: " << move->damage << endl;
		 }

	 delete move;
	 }
	
	
 }


