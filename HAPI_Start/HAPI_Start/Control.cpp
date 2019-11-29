#include "Control.h"

Control::~Control()
{
}

void Control::ControlInPut()
{
	const HAPI_TKeyboardData& KeyData = HAPI.GetKeyboardData();
	const HAPI_TControllerData& ControlData = HAPI.GetControllerData(0);

	//		Controll Input, D-pad and Controll Input, analogue
	if (ControlData.isAttached != false)
	{
		if (ControlData.digitalButtons[HK_DIGITAL_DPAD_UP] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] > LeftDeadZoneMax)
		{
			-= Speed;
		}
		if (ControlData.digitalButtons[HK_DIGITAL_DPAD_DOWN] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] < LeftDeadZoneMin)
		{
			 += Speed;
		}
		if (ControlData.digitalButtons[HK_DIGITAL_DPAD_LEFT] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] < LeftDeadZoneMin)
		{
			 -= Speed;
		}
		if (ControlData.digitalButtons[HK_DIGITAL_DPAD_RIGHT] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] > LeftDeadZoneMax)
		{
			 += Speed;
		}
	}

	//	Keyboard Input 
	if (KeyData.scanCode['W'])
	{
		 -= Speed;
	}
	if (KeyData.scanCode['A'])
	{
		 -= Speed;
	}
	if (KeyData.scanCode['S'])
	{
		 += Speed;
	}
	if (KeyData.scanCode['D'])
	{
		 += Speed;
	}
}

void Control::GetInPut()
{
	return ControlInPut();
}
