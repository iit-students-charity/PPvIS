#include "stdafx.h"
#include "Boeing_777_psg.h"


Boeing_777_psg::Boeing_777_psg(std::string b) : PassengerPlane::PassengerPlane(b)
{
	Plane::model = "Boeing-777 <passenger>";
	Plane::currentArp = "Minsk";
	Plane::speed = 940;
	Plane::maxRange = 11000;
	Plane::price = 100000;
	Plane::costPerKm = 320;
	Plane::maxLoad = 190000;
}