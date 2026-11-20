#include "Link.h"
#include "LinkedListMoves.h"
void Link::Display()
{
	cout << "Person: " << data->person << endl;
	cout << "Turn Number: " << data->turnNum << endl;
	cout << "Move: " << data->move << endl;
	cout << "Damage: " << data->damage << endl;
}

int Link::GetData()
{
	return 0;
}
