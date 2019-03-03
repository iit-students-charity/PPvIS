#include "stdafx.h"
#include "PassengerPlane.h"


PassengerPlane::PassengerPlane(std::string b) : Plane::Plane(b)
{
}

void PassengerPlane::setPassengers(size_t psng)
{
	passengers = psng;
}

size_t PassengerPlane::getPassengers()
{
	return passengers;
}