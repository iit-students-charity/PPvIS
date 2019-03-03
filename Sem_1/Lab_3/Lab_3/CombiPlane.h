#pragma once
#include "CargoPlane.h"
#include "PassengerPlane.h"
class CombiPlane :
	public CargoPlane,
	public PassengerPlane
{
public:
	CombiPlane(std::string);
};

