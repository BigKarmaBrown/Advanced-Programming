using namespace std;
#include <iostream>
#include "Menu.h"
#include "Player.h"
#include "Gamestate.h"
#include "NightCycle.h"
#include "LinkedListMoves.h"
#include "Tree.h"

int GameState::AccountTurns = 0;
//A static member declares a variable that there is only one instance of
// which is shared by all objects. 
// It belongs to one class and is initialised outside of the class 
// unless with const.
int main()
{
    Menu menu;
    Enemy* enemy = NULL;
    Player* player = NULL;
    //A pointer is defined. 
   // Which can only be passed in information of a specified type. 
    GameState* result = NULL;
    GameState::battleResult::playerNotInFight;
    GameState gameState();

    NightCycle* cycle = new NightCycle();


    //LinkedListMoves* battleHistory;
    LinkedListMoves* battleHistory = new LinkedListMoves();
    Tree* tree = new Tree();
        
    
    menu.StartMenu(player, enemy, result, cycle, battleHistory);
}