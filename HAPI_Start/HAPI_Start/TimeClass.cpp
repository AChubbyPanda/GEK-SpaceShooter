#include "TimeClass.h"
#include "HAPI_lib.h"

TimeClass* TimeClass::timeClass = NULL;

TimeClass::TimeClass()
	: newTime(0)
	, oldTime(0)
{

}

TimeClass::~TimeClass()
{
}


int TimeClass::getDelta()
{
	return newTime;
}

TimeClass* TimeClass::getInstance()
{
	if (timeClass == NULL)
	{
		timeClass = new TimeClass();
	}
	return timeClass;
}

void TimeClass::update()
{
	newTime = HAPI.GetTime() - oldTime;
	oldTime = newTime;
}
