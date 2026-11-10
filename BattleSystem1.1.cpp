using namespace std;
#include <iostream>
#include "Menu.h"
#include "Player.h"
#include "Gamestate.h"
#include "NightCycle.h"


int main()
{
    Menu menu;
    Enemy* enemy = NULL;
    Player* player = NULL;
    GameState* gameState = NULL;
    NightCycle* cycle = 0;
    menu.StartMenu(player, enemy, gameState, cycle);


}