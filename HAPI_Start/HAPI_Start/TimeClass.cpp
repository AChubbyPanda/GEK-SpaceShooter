#include "TimeClass.h"
#include "HAPI_lib.h"

TimeClass* TimeClass::timeClass = NULL;

TimeClass::TimeClass()
	: newTime(HAPI.GetTime())
	, oldTime(0)
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

TimeClass* TimeClass::getInstance()
{
	if (timeClass == NULL)
	{
		timeClass = new TimeClass();
	}
	return timeClass;
}
