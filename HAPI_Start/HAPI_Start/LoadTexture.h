#pragma once
#include <HAPI_lib.h>

using namespace HAPISPACE;

class Texture
{
	bool Load(const std::string& FileName);
	
public:
	BYTE* texturePointer;
	int texWidth;
	int texHeight;
	static Texture* createTexture(const std::string name, const std::string& fileName);
};