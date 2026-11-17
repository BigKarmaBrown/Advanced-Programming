using namespace std;
#include <iostream>
#include "Menu.h"
#include "Player.h"
#include "Gamestate.h"
#include "NightCycle.h"
#include "PriorityQueue.h"
#include "Tree.h"


int main()
{
    Menu menu;
    Enemy* enemy = NULL;
    Player* player = NULL;
    GameState* result = NULL;
    GameState::battleResult::playerNotInFight;
    NightCycle* cycle = 0;
    PriorityQueue<GameState::BattleMove>battleHistory(111);
  
    
    Tree* tree = new Tree();
    
     GameState gameState(&battleHistory, tree);
    menu.StartMenu(player, enemy, result, cycle, &battleHistory, tree);
}