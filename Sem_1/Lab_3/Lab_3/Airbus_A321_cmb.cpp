#include "stdafx.h"
#include "Airbus_A321_cmb.h"


Airbus_A321_cmb::Airbus_A321_cmb(std::string b) : CombiPlane::CombiPlane(b)
{
	Plane::model = "Airbus A321 <combi>";
	Plane::currentArp = "Minsk";
	Plane::speed = 870;
	Plane::maxRange = 6500;
	Plane::price = 30000;
	Plane::costPerKm = 70;
	Plane::maxLoad = 20000;
}
