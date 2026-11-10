#include "NightCycle.h"


bool NightCycle::calcDay(NightCycle* cycle)
{
	bool check = cycle->night % 2;
	if (check == false) {

		return false;
	}
	else {
		return true;
	}
}
