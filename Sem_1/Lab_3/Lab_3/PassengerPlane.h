#pragma once
#include "Plane.h"
class PassengerPlane :
	public Plane
{
private:
	size_t passengers;
public:
	PassengerPlane(std::string);
	void setPassengers(size_t);
	size_t getPassengers();
};

