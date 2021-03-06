#include "stdafx.h"
#include "Map.h"
#include "Player.h"
#include "Plane.h"
#include "Bot.h"
	#include "CargoPlane.h"
		#include "Boeing_737_crg.h"
	#include "PassengerPlane.h"
		#include "An_2_psg.h"
		#include "ATR_72_psg.h"
		#include "Boeing_777_psg.h"
	#include "CombiPlane.h"
		#include "Airbus_A321_cmb.h"

#include <iostream>
#include <windows.h>

const size_t turnsToWin = 50;

int main()
{
	std::string file;
	std::string name;
	std::cout << "Please enter map file name (World_1.txt default): ";
	std::cin >> file;
	std::cout << "Enter your company's name: ";
	std::cin >> name;
	std::system("cls");

	Map mp(file);
	Player pl(name);
	Bot bot("Jmih Airlines", "World_1.txt");

	for (size_t turn = 0; turn < turnsToWin; turn++)
	{
		size_t choise;
		bool isAnyPlane = true;
		bool skip = false;

		//////////FIRST SCREEN//////////
		std::cout << "1- Buy aircraft" << std::endl;
		if (pl.getPlanes().size() != 0)
		{
			isAnyPlane = true;
			std::cout << "2- Load flight" << std::endl;
			std::cout << "3- Skip turn" << std::endl;;
		}
		else
		{
			isAnyPlane = false;
		}
		std::cin >> choise;

		//Buying plane
		if (choise == 1)
		{
			size_t choisePlane;
			bool isPlanePurch = false;

			system("cls");
			while (!isPlanePurch)
			{
				std::cout << "Buy aircraft" << std::endl << std::endl;
				std::cout << "1- An-2: 2500 coins" << std::endl;
				std::cout << "2- ATR-72: 10000 coins" << std::endl;
				std::cout << "3- Boeing-737: 50000 coins" << std::endl;
				std::cout << "4- Boeing-777: 100000 coins" << std::endl;
				std::cout << "9- Exit" << std::endl;
				std::cin >> choisePlane;
				if (2500 <= pl.getCash() && choisePlane == 1)
				{
					std::string boardNumber;
					std::cout << "Enter board number: ";
					std::cin >> boardNumber;
					pl.buyPlane(An_2_psg(boardNumber));
					isAnyPlane = true;
					isPlanePurch = true;
				}
				else if (5000 <= pl.getCash() && choisePlane == 2)
				{
					std::string boardNumber;
					std::cout << "Enter board number: ";
					std::cin >> boardNumber;
					pl.buyPlane(ATR_72_psg(boardNumber));
					isAnyPlane = true;
					isPlanePurch = true;
				}
				else if (50000 <= pl.getCash() && choisePlane == 3)
				{
					std::string boardNumber;
					std::cout << "Enter board number: ";
					std::cin >> boardNumber;
					pl.buyPlane(Boeing_737_crg(boardNumber));
					isAnyPlane = true;
					isPlanePurch = true;
				}
				else if (100000 <= pl.getCash() && choisePlane == 4)
				{
					std::string boardNumber;
					std::cout << "Enter board number: ";
					std::cin >> boardNumber;
					pl.buyPlane(Boeing_777_psg(boardNumber));
					isAnyPlane = true;
					isPlanePurch = true;
				}
				else if (choisePlane == 9)
				{
					turn--;
					isPlanePurch = true;
					skip = true;
				}
				else
				{
					std::cout << "You don't have enough money for this aircraft!" <<
						std::endl;
					choise = 0;
					system("cls");
				}
			}
		}
		//Loading flight
		else if (choise == 2 && isAnyPlane == true)
		{
			size_t dest;
			size_t plane;
			size_t numb = 1;
			std::vector <size_t> selPlane;

			for (size_t i = 0; i < pl.getPlanes().size(); i++)
			{
				if (pl.getPlanes()[i].getTurnsToDest() == 0)
				{
					std::cout << numb << "- " << pl.getPlanes()[i].getModel()
						<< " " << pl.getPlanes()[i].getBoardNumber() << std::endl;
					numb++;
					selPlane.push_back(i);
				}
			}
			numb = 1;
			std::cin >> plane;
			plane = selPlane[plane - 1];
			

			std::vector <std::string> avalaibleArps;
			for (size_t i = 0; i < mp.getArps().size(); i++)
			{
				if 
				(
					pl.getPlanes()[plane].getMaxRange() >=
						mp.getRouteLength
						(
							pl.getPlanes()[plane].getCurrentArp(),
							mp.getArps()[i]
						)
					&& mp.getRouteLength
					(
						pl.getPlanes()[plane].getCurrentArp(),
						mp.getArps()[i]
					) != 0
				)
				{
					avalaibleArps.push_back(mp.getArps()[i]);
					std::cout << numb << "- " << mp.getArps()[i] << std::endl;
					numb++;
				}
			}
			std::cin >> dest;
			numb = 0;
			while (avalaibleArps[dest - 1] != mp.getArps()[numb])
			{
				numb++;
			}

			size_t cargo;
			bool isRight = false;
			while (!isRight)
			{
				std::cout << "Enter % of cargo" << std::endl;
				std::cin >> cargo;
				if (cargo <= 100 && cargo >= 0)
				{
					isRight = true;
				}
			}

			pl.loadFlight(mp, mp.getArps()[numb], pl.getPlanes()[plane], cargo);
		}

		system("cls");

		for (size_t i = 0; i < pl.getPlanes().size(); i++)
		{
			if (pl.getPlanes()[i].getTurnsToDest() != 0)
			{
				pl.getPlanes()[i].wearout();
			}
		}

		bot.action();

		pl.endTurn(pl, turn);
		bot.endTurn(bot, turn);
		//////////SECOND SCREEN//////////
			system("cls");
			std::cout << '\t' << '\t' << '\t' << '\t' << '\t' <<
				"Turn " << turn + 1 << std::endl;
			////////PLAYER'S SCREEN////////
			std::cout << '\t' << '\t' << '\t' << '\t' << '\t' <<
				pl.getName() << std::endl;

			std::cout << '\t' << '\t' << '\t' << '\t' << '\t' <<
				pl.getCash() << " coins" << std::endl << std::endl;

			for (size_t i = 0; i < pl.getPlanes().size(); i++)
			{
				std::cout << pl.getPlanes()[i].getModel() << " " <<
					pl.getPlanes()[i].getBoardNumber() <<
					" [" << pl.getPlanes()[i].getResource() << "]" << ": ";
				if (pl.getPlanes()[i].getTurnsToDest() != 0)
				{
					std::cout << "Left " << pl.getPlanes()[i].getTurnsToDest() <<
						" turn(s) to " << pl.getPlanes()[i].getCurrentArp() << std::endl;
					pl.getPlanes()[i].setTurnsToDest(pl.getPlanes()[i].getTurnsToDest() - 1);
				}
				else if (pl.getPlanes()[i].getTurnsToDest() == 0)
				{
					std::cout << "Holding in " << pl.getPlanes()[i].getCurrentArp() << std::endl;
				}
				if (pl.getPlanes()[i].getResource() == 0)
				{
					std::cout << "Crashed! -10000 coins" << std::endl;
					pl.getPlanes().erase(pl.getPlanes().begin() + i);
					pl.setCash(pl.getCash() - 1000);
				}
				std::cout << std::endl;
				system("pause");
				system("cls");
			////////BOT'S SCREEN////////
				std::cout << '\t' << '\t' << '\t' << '\t' << '\t' <<
					"Turn " << turn + 1 << std::endl;
				std::cout << '\t' << '\t' << '\t' << '\t' << '\t' <<
					bot.getName() << std::endl;

				std::cout << '\t' << '\t' << '\t' << '\t' << '\t' <<
					bot.getCash() << " coins" << std::endl << std::endl;

				for (size_t i = 0; i < bot.getPlanes().size(); i++)
				{
					std::cout << bot.getPlanes()[i].getModel() << " " <<
						bot.getPlanes()[i].getBoardNumber() <<
						" [" << bot.getPlanes()[i].getResource() << "]" << ": ";
					if (bot.getPlanes()[i].getTurnsToDest() != 0)
					{
						std::cout << "Left " << bot.getPlanes()[i].getTurnsToDest() <<
							" turn(s) to " << bot.getPlanes()[i].getCurrentArp() << std::endl;
						bot.getPlanes()[i].setTurnsToDest(bot.getPlanes()[i].getTurnsToDest() - 1);
					}
					else if (bot.getPlanes()[i].getTurnsToDest() == 0)
					{
						std::cout << "Holding in " << bot.getPlanes()[i].getCurrentArp() << std::endl;
					}
					if (bot.getPlanes()[i].getResource() == 0)
					{
						std::cout << "Crashed! -10000 coins" << std::endl;
						bot.getPlanes().erase(bot.getPlanes().begin() + i);
						bot.setCash(bot.getCash() - 1000);
					}
				}
			}
			std::cout << std::endl;
			system("pause");
			system("cls");
	}
	system("pause");
    return 0;
}
