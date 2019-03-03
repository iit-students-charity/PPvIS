#include "stdafx.h"
#include "ATR_72_psg.h"


ATR_72_psg::ATR_72_psg(std::string b) : PassengerPlane::PassengerPlane(b)
{
	Plane::model = "ATR-72 <passenger>";
	Plane::currentArp = "Minsk";
	Plane::speed = 511;
	Plane::maxRange = 1325;
	Plane::price = 5000;
	Plane::costPerKm = 127;
	Plane::maxLoad = 7500;
}
