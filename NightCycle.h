#pragma once
using namespace std;
#include <iostream>


class NightCycle
{
protected:
	int night;
public:
	NightCycle(int night = 0) : night(night){}

	NightCycle operator+(const NightCycle& obj) {
		NightCycle temp;
		
		temp.night = obj.night + night;
	}
	
	bool calcDay(NightCycle* cycle);
	
};

