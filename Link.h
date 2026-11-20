#pragma once
using namespace std;
#include <iostream>
//#include "LinkedListMoves.h"


struct battleMove;
class Link
{
public:

	battleMove*data;
	Link* next;
	void Display();
	int GetData();
	Link(battleMove* data) : data(data), next(nullptr)
	{
		//this->data = new(battleMove);
	};
};

