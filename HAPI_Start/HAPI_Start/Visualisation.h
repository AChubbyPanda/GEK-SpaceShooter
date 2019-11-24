#pragma once
#include <HAPI_lib.h>

using namespace HAPISPACE;

class Visualisation
{
private:
	BYTE* Screen;

	// Screen size
	int v_ScreenWidth{ 1280 };
	int v_ScreenHeight{ 720 };

	void ClearToColour(HAPI_TColour Col);
	void ClearToGray(BYTE grey = 0);
	void SetPixel(BYTE* Screen, int v_PosX, int v_PosY, int v_ScreenWidth, HAPI_TColour Col);
	Visualisation();
	~Visualisation();

public:
	static Visualisation* Get();
	static void Initialise();
	static void Shutdown();
};

