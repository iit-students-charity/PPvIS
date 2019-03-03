#include "stdafx.h"
#include "Player.h"
#include "Map"
#include <iostream>


Player::Player(std::string nm)
{
	name = nm;
	cash = 2500;
}

void Player::buyPlane(Plane pln)
{
	cash = cash - pln.getPrice();
	planes.push_back(pln);
}
void Player::loadFlight(Map mp, std::string destination, Plane& pln, size_t cargo)
{
	size_t curr = 0;
	size_t dest = 0;
	size_t turns = 0;
	std::vector <std::string> arps = mp.getArps();
	std::vector <std::vector <size_t>> rt = mp.getRoute();

	while (destination != arps[dest])
	{
		dest++;
	}
	while (pln.getCurrentArp() != arps[curr])
	{
		curr++;
	}
	turns = rt[curr][dest] / pln.getSpeed();
	if (turns == 0)
	{
		turns = 1;
	}

	float crg = float(cargo) / 100;
	float a = rt[curr][dest] * pln.getCostPerKm() * crg;
	float b = crg * pln.getMaxLoad() * 12;
	cash = cash - a + b;

	pln.setTurnsToDest(turns);
	pln.setCurrentArp(arps[dest]);
	pln.setWearoutPerTurn(crg);
	pln.setIsOnFlight(true);
}
int Player::getCash()
{
	return cash;
}
void Player::setCash(int ch)
{
	cash = ch;
}
size_t Player::getTurn()
{
	return turn;
}
void Player::setTurn(size_t trn)
{
	turn = trn;
}
std::vector <Plane>& Player::getPlanes()
{
	return planes;
}
std::string Player::getName()
{
	return name;
}
void Player::endTurn(Player& pl, size_t trn)
{
	for (size_t i = 0; i < pl.planes.size(); i++)
	{
		if (pl.planes[i].getTurnsToDest() == 0)
		{
			pl.planes[i].setIsOnFlight(false);
		}
	}

	pl.turn = trn;
}
