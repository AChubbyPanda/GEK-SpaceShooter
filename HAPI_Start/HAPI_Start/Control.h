#pragma once
#ifndef Control_h //This is used when more than one header file is compiling the same header file.
#define Control_h //This is used when more than one header file is compiling the same header file.

#include <HAPI_lib.h>

using namespace HAPISPACE;

class Control 
{
private:
	const HAPI_TKeyboardData& KeyData = HAPI.GetKeyboardData();
	const HAPI_TControllerData& ControlData = HAPI.GetControllerData(0);

	int Speed = 1;

	const int LeftDeadZoneMax = 8000;
	const int LeftDeadZoneMin = -8000;

public:
	void ControlInPut();

protected:
	void GetInPut();
	~Control();
};
#endif // Control_h //This is used when more than one header file is compiling the same header file.

