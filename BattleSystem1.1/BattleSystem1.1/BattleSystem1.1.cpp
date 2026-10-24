using namespace std;
#include <iostream>
#include "Menu.h"
#include "Player.h"
#include "Gamestate.h"


int main()
{
    Menu menu;
    Enemy* enemy = NULL;
    Player* player = NULL;
    GameState* gameState = NULL;

    menu.StartMenu(player, enemy, gameState);
}