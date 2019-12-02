#pragma once
#include <HAPI_lib.h>
#include "Rectangle.h"
#include "Player.h"
#include <string>

using namespace HAPISPACE;

class Visualisation
{
private:
	BYTE* Screen;
	BYTE* TextureData;

	int TexWidth{ 0 };
	int TexHeight{ 0 };
	// Screen size
	int v_ScreenWidth;
	int v_ScreenHeight;
	std::vector<Visualisation*> m_Vis;

	void ClearToColour(HAPI_TColour Col);
	void ClearToGray(BYTE grey = 0);
	void SetPixel(BYTE* Screen, int v_PosX, int v_PosY, int v_ScreenWidth, HAPI_TColour Col);

	bool LoadTexture(const std::string& FileName);

	void Blit(BYTE* Screen, int ScreenWidth, int ScreenHeight, int PosX, int PosY);
	void BlitzAlpha(BYTE* Position, int ScreenWidth, int ScreenHeight, int PosX, int PosY);
	
public:

	unsigned int CreateSprite(const std::string& filename, const std::string& name);
	void Draw(unsigned int ID, int PosX, int PosY);

	static Visualisation* Get();
	static void Initialise();
	static void Shutdown();
	Visualisation();
	~Visualisation();

};

