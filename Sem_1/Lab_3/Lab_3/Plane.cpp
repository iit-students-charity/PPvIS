#include "stdafx.h"
#include "Plane.h"


Plane::Plane(std::string brdnb)
{
	resource = 100;
	boardNumber = brdnb;
	currentArp = "Minsk";
	turnsToDest = 0;
}

void Plane::wearout()
{
	resource -= 5 * wearoutPerTurn;
}

size_t Plane::getResource()
{
	return resource;
}

void Plane::setWearoutPerTurn(float wpt)
{
	wearoutPerTurn = wpt;
}

size_t Plane::getPrice()
{
	return price;
}

size_t Plane::getSpeed()
{
	return speed;
}

std::string Plane::getCurrentArp()
{
	return currentArp;
}

std::string Plane::getModel()
{
	return model;
}

std::string Plane::getBoardNumber()
{
	return boardNumber;
}

size_t Plane::getMaxRange()
{
	return maxRange;
}

size_t Plane::getTurnsToDest()
{
	return turnsToDest;
}

void Plane::setTurnsToDest(size_t turns)
{
	turnsToDest = turns;
}

void Plane::setCurrentArp(std::string arp)
{
	currentArp = arp;
}

size_t Plane::getCostPerKm()
{
	return costPerKm;
}

size_t Plane::getMaxLoad()
{
	return maxLoad;
}

void Plane::setIsOnFlight(bool flt)
{
	isOnFlight = flt;
}

bool Plane::getIsOnFlight()
{
	return isOnFlight;
}