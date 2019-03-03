#pragma once
#include "Plane.h"
#include <string>

class CargoPlane :
	public Plane
{
private:
	size_t cargo;
public:
	CargoPlane(std::string);
};

