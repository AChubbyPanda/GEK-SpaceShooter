#include "Visualisation.h"

static Visualisation* Instance = nullptr;

Visualisation::Visualisation()
	: Screen(nullptr)
{
}

Visualisation::~Visualisation()
{
}

void Visualisation::Initialise()
{
	if (!Instance)
	{
		Instance = new Visualisation();
		// Check for instance already created
	}

	if (!HAPI.Initialise(Instance->v_ScreenWidth, Instance->v_ScreenHeight, "Maven, Neil, V8039070"))
	{
		return;
	}

	Instance->Screen = HAPI.GetScreenPointer();

	HAPI.SetShowFPS(true);
}

void Visualisation::Shutdown()
{
	delete Instance;
}

Visualisation* Visualisation::Get()
{
	return Instance;
}

void Visualisation::ClearToColour(HAPI_TColour Col)
{
	HAPI_TColour col{ HAPI_TColour::BLACK };

	BYTE* Temp{ Screen };
	for (int i = 0; i < v_ScreenWidth * v_ScreenHeight; i++)
	{
		memcpy(Temp, &Col, 4);
		Temp += 4;
	}
}

void Visualisation::ClearToGray(BYTE grey)
{
	memset(Screen, grey, ((int64_t)v_ScreenWidth * (int64_t)v_ScreenHeight) * 4);
}

void Visualisation::SetPixel(BYTE* Screen, int v_PosX, int v_PosY, int ScreenWidth, HAPI_TColour Col)
{
	unsigned int OffSet = (v_PosX + v_PosY * ScreenWidth) * 4;
	memcpy(Screen + OffSet, &Col, sizeof(Col));
}