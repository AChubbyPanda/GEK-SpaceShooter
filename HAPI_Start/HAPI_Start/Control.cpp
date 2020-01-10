#include "Control.h"

Control::~Control()
{
}

void Control::controlInPut()
{
	//const HAPI_TKeyboardData& KeyData = HAPI.GetKeyboardData();
	//const HAPI_TControllerData& ControlData = HAPI.GetControllerData(0);

	////		Controll Input, D-pad and Controll Input, analogue
	//if (ControlData.isAttached != false)
	//{
	//	if (ControlData.digitalButtons[HK_DIGITAL_DPAD_UP] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] > LeftDeadZoneMax)
	//	{
	//		 m_position.y -= Speed;
	//	}
	//	if (ControlData.digitalButtons[HK_DIGITAL_DPAD_DOWN] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_Y] < LeftDeadZoneMin)
	//	{
	//		m_position.x -= Speed;
	//	}
	//	if (ControlData.digitalButtons[HK_DIGITAL_DPAD_LEFT] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] < LeftDeadZoneMin)
	//	{
	//		  m_position.y += Speed;
	//	}
	//	if (ControlData.digitalButtons[HK_DIGITAL_DPAD_RIGHT] || ControlData.analogueButtons[HK_ANALOGUE_LEFT_THUMB_X] > LeftDeadZoneMax)
	//	{
	//		 m_position.x += Speed;
	//	}
	//}

	////	Keyboard Input 
	//if (KeyData.scanCode['W'])
	//{
	//	 m_position.y -= Speed;
	//}
	//if (KeyData.scanCode['A'])
	//{
	//	m_position.x -= Speed;
	//	 
	//}
	//if (KeyData.scanCode['S'])
	//{
	//	 m_position.y += Speed;
	//}
	//if (KeyData.scanCode['D'])
	//{
	//	 m_position.x += Speed;
	//}
}

void Control::getInPut()
{
	return controlInPut();
}
