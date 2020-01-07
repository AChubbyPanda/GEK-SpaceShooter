#pragma once
#include <HAPI_lib.h>

using namespace HAPISPACE;

class LoadTexture
{
	bool Load(const std::string& FileName);
	
protected:
	int texWidth;
	int texHeight;
	
public:
	BYTE* texturePointer;
	static LoadTexture* createTexture(const std::string& name, const std::string& fileName);
};