#include "stdafx.h"
#include "An_2_psg.h"


An_2_psg::An_2_psg(std::string b) : PassengerPlane::PassengerPlane(b)
{
	Plane::model = "An-2 <passenger>";
	Plane::currentArp = "Minsk";
	Plane::speed = 320;
	Plane::maxRange = 990;
	Plane::price = 2500;
	Plane::costPerKm = 45;
	Plane::maxLoad = 3200;
}

