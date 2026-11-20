#pragma once
using namespace std;
#include <iostream>


class NightCycle
{
protected:
	int night;
public:
	NightCycle(int night = 0) : night(night){}

	NightCycle operator+(int) {
		NightCycle temp = *this;
		night++;
		return temp;
	}
	//Within the class stating that if objects have a specified operator, 
	// which data to change. 
	// The object itself is passed in through the parameter. 
	bool calcDay(NightCycle* cycle);
	
};

