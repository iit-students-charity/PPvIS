#pragma once
#include "Plane.h"
#include "Map.h"
#include <vector>
#include <string>

class Player
{
protected:
	std::string name; //+
	int cash; //+
	size_t turn; //+?
	std::vector <Plane> planes; //+
public:
	Player(std::string);

	void buyPlane(Plane); //+
	void loadFlight(Map, std::string, Plane&, size_t); //+
	int getCash(); //+
	void setCash(int); //+
	size_t getTurn(); 
	void setTurn(size_t); //+
	std::vector <Plane>& getPlanes(); //+
	std::string getName(); //+
	void endTurn(Player&, size_t);
};
