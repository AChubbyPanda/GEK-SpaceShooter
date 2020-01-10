#include "LoadTexture.h"

bool Texture::Load(const std::string& fileName)
{
	if (!HAPI.LoadTexture(fileName, &texturePointer, texWidth, texHeight))
	{
		HAPI.UserMessage("ERROR ", "Texture Failed to load ");
		return false;
	}
	return true;
}

Texture* Texture::createTexture(const std::string& name, const std::string& fileName)
{
	Texture* tex = new Texture();

	if (!tex->Load(fileName))
	{
		delete tex;
		return false;
	};

	return tex;
}