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
			m_PosY -= Speed;
		}
		if (ControlData.digitalButtons[HK_DIGITAL_DPAD_DOWN] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] < LeftDeadZoneMin)
		{
			m_PosY += Speed;
		}
		if (ControlData.digitalButtons[HK_DIGITAL_DPAD_LEFT] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] < LeftDeadZoneMin)
		{
			m_PosX -= Speed;
		}
		if (ControlData.digitalButtons[HK_DIGITAL_DPAD_RIGHT] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] > LeftDeadZoneMax)
		{
			m_PosX += Speed;
		}
	}

	//	Keyboard Input 
	if (KeyData.scanCode['W'])
	{
		m_PosY -= Speed;
	}
	if (KeyData.scanCode['A'])
	{
		m_PosX -= Speed;
	}
	if (KeyData.scanCode['S'])
	{
		m_PosY += Speed;
	}
	if (KeyData.scanCode['D'])
	{
		m_PosX += Speed;
	}

	//This is for the rumble in the middle of the sceen
	if (m_PosX > 540 && m_PosX < 740 && m_PosY > 260 && m_PosY < 460)
	{
		HAPI.SetControllerRumble(0, 20000, 20000);
	}
	else
	{
		HAPI.SetControllerRumble(0, 0, 0);
	}
}

void Control::GetInPut()
{
	return ControlInPut();
}
