#pragma once
#include "GameState.h"
#include "Menu.h"
#include "ErrorHandler.h"
#include "assert.h"
#include "NightCycle.h"
using namespace std;
#include <iostream>

bool GameState::GameStart(Player* player, Enemy* enemy, GameState* gameState, NightCycle* cycle)
{
	system("CLS");
	srand(static_cast<unsigned int>(time(0)));
	int whosTurn = rand() % 2 + 1;

	

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

		if (player->health <= 0 || enemy->health <= 0) {
			try {
				displayWinner(player, enemy);
			if (player->health <= 0) {
				return false;
			}
			return true;
				break;
			}
			catch(ErrorHandler e)
			{
				cout << "Exception: " << e.cantDisplayWInner();
			
			}
			
			
		}
		else if (whosTurn == 1)
		{
			player->takeTurn(player, enemy);
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
			throw(false); 

			
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
		
		displayDead(player);
		delete enemy;
		enemy = NULL;
		return;
	}
	else if (player->health <= 0)
	{
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		cout << "-----------------------------------------------------You Lost The Fight-------------------------------------------------" << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		
		displayDead(player);
		delete player;
		player = NULL;
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
				cout << "player turn" << endl;
			}
			else if (turn == 2) {
				cout << "enemys turn" << endl;
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


