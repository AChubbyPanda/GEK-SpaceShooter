#pragma once
#include <HAPI_lib.h>

using namespace HAPISPACE;

class LoadTexture
{
	bool Load(const std::string& FileName);
	
protected:
	int m_TexWidth;
	int m_TexHeight;
	
public:
	BYTE* m_TexturePointer;
	static LoadTexture* CreateTexture(const std::string& Name, const std::string& FileName);
};