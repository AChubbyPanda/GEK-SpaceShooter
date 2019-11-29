#pragma once

#include <HAPI_lib.h>
#include <Vector>

using namespace HAPISPACE;

class Entity
{
private:
	unsigned int textureID;

public:
	Entity(const std::string& FileName, const std::string Name);
	~Entity();
};

