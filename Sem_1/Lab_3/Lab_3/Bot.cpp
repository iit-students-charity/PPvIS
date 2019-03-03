#include "stdafx.h"
#include "Map.h"
#include "Bot.h"
#include "Boeing_737_crg.h"
#include "PassengerPlane.h"
#include "An_2_psg.h"
#include "ATR_72_psg.h"
#include "Boeing_777_psg.h"

#include <string>
#include <vector>

Bot::Bot(std::string nm, std::string map) : Player::Player(nm)
{
	mp = Map(map);
	name = nm;
	cash = 2500;
}

void Bot::action()
{
	bool an2 = false;
	bool atr72 = false;
	bool b737 = false;

	for (size_t i = 0; i < planes.size(); i++)
	{
		if (planes[i].getModel() == "An-2 <passenger>")
		{
			an2 = true;
		}
		else if (planes[i].getModel() == "ATR-72 <passenger>")
		{
			atr72 = true;
		}
		else if (planes[i].getModel() == "Boeing-737 <cargo>")
		{
			b737 = true;
		}
	}

	size_t rnd;
	if (planes.size() == 0)
	{
		rnd = 1;
	}
	else
	{
		rnd = rand() % 2 + 1;
	}

	switch (rnd)
	{
	case 1:
		if (cash >= 2500 && cash <= 9999 && !an2)
		{
			this->buyPlane(An_2_psg("JA-" + std::to_string(this->planes.size() + 1)));
		}
		else if (cash >= 10000 && cash <= 49999 && !atr72)
		{
			this->buyPlane(ATR_72_psg("JA-" + std::to_string(this->planes.size() + 1)));
		}
		else if (cash >= 50000 && cash <= 99999 && !b737)
		{
			this->buyPlane(Boeing_737_crg("JA-" + std::to_string(this->planes.size() + 1)));
		}
		else if (cash >= 100000)
		{
			this->buyPlane(Boeing_777_psg("JA-" + std::to_string(this->planes.size() + 1)));
		}
		break;
	case 2:
		if (planes.size() != 0)
		{
			size_t rand_pln = rand() % planes.size() + 1;
			if (planes.size() == 1)
			{
				rand_pln = 0;
				if (planes[0].getIsOnFlight() == true)
				{
					break;
				}
			}
			else
			{
				while (rand_pln > planes.size() - 1)
				{
					rand_pln = rand() % planes.size() + 1;
				}
			}
			
			size_t rand_crg = 999;
			while (rand_crg < 75 || rand_crg > 100)
			{
				rand_crg = rand() % 100 + 1;
			}

			size_t rand_arp = rand() % mp.getArps().size() + 1;
			while 
				(
					planes[rand_pln].getMaxRange() < mp.getRouteLength(mp.getArps()[rand_arp], planes[rand_pln].getCurrentArp())
					|| mp.getRouteLength(mp.getArps()[rand_arp], planes[rand_pln].getCurrentArp()) == 0
					|| planes[rand_pln].getIsOnFlight() == true
				)
			{
				rand_arp = rand() % mp.getArps().size();
			}

			this->loadFlight(mp, mp.getArps()[rand_arp], planes[rand_pln], rand_crg);
		}
		break;
	case 3:
		break;
	}
}
