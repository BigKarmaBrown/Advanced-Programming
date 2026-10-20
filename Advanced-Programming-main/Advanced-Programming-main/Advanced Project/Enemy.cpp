#include "Enemy.h"
#include "Player.h"
using namespace std;


void Enemy::attack(float damage, bool hit, Player* player)
{

}

void Enemy::run()
{
}

void Enemy::brace()
{

}

void Enemy::taketurn()
{
	srand(time(0));
	int randomNumber = rand() % 3 + 1;
	randomNumber - 1;

	switch (randomNumber) 
	{
	case 0:
		attack();
		break;
	case 1:
		run();
		break;
	case 2:
		brace();
		break;

	default:
		cout << "------------------------------ Enemy Took an invalid turn ---------------------------" << endl;
	}
}
