#pragma once
#include <HAPI_lib.h>
#include "Rectangle.h"
#include <string>
#include <unordered_map>
#include "LoadTexture.h"
#include "Entity.h"

using namespace HAPISPACE;
class LoadTexture;
class Entity;

class Visualisation : public LoadTexture 
{
private:

	BYTE* m_ScreenPointer;

	// Screen size
	int m_ScreenWidth;
	int m_ScreenHeight;
	Rectangle m_ScreenRect;
	std::unordered_map<std::string, LoadTexture*> m_EntityMap;

	void ClearToColour(HAPI_TColour Col);
	void ClearToGray(BYTE grey = 0);
	void SetPixel(BYTE* Screen, int v_PosX, int v_PosY, int v_ScreenWidth, HAPI_TColour Col);

	//bool LoadTexture(const std::string& FileName, BYTE* TexturePointer);

	void Blit(BYTE* Screen, int m_ScreenWidth, int m_ScreenHeight, int PosX, int PosY, BYTE* TexturePointer);
	void BlitzAlpha(BYTE* Position, int m_ScreenWidth, int m_ScreenHeight, int PosX, int PosY, BYTE* TexturePointer);
	
public:
	//std::map< std::string, int > mapLocation;
	bool CreateSprite(const std::string& Name, const std::string& FileName);
	void Draw(const std::string Name, int PosX, int PosY);

	bool Initialise(int m_ScreenWidth, int m_ScreenHeight);
	static void Shutdown();
	Visualisation();
	~Visualisation();

};

