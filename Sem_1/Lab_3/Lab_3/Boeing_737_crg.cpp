#include "stdafx.h"
#include "Boeing_737_crg.h"


Boeing_737_crg::Boeing_737_crg(std::string b) : CargoPlane::CargoPlane(b)
{
	Plane::model = "Boeing-737 <cargo>";
	Plane::currentArp = "Minsk";
	Plane::speed = 850;
	Plane::maxRange = 5800;
	Plane::price = 50000;
	Plane::costPerKm = 645;
	Plane::maxLoad = 38000;
}

