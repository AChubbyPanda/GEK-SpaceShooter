#include "LoadTexture.h"

bool LoadTexture::Load(const std::string& fileName)
{
	if (!HAPI.LoadTexture(fileName, &texturePointer, texWidth, texHeight))
	{
		HAPI.UserMessage("ERROR ", "Texture Failed to load ");
		return false;
	}
	return true;
}

LoadTexture* LoadTexture::createTexture(const std::string& name, const std::string& fileName)
{
	LoadTexture* tex = new LoadTexture();

	if (!tex->Load(fileName))
	{
		delete tex;
		return false;
	};

	return tex;
}