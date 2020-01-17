#include "TimeClass.h"
#include "HAPI_lib.h"

TimeClass::TimeClass()
	: oldTime(newTime)
	, newTime (HAPI.GetTime())
{

}

TimeClass::~TimeClass()
{
}


void TimeClass::delta(int oldT, int newT)
{
	oldT = oldTime;
	newT = newTime;

	newT - oldT / 16;
}
