#pragma once
#include <string>

class Plane
{
private:
	std::string boardNumber; //+
	size_t resource; //+
	float wearoutPerTurn; //+
protected:
	bool isOnFlight; //+
	std::string model; //+
	size_t price; //+
	size_t speed; //+
	size_t maxRange; //+
	size_t maxLoad; //+
	size_t costPerKm; //+
	std::string currentArp; //+
	size_t turnsToDest; //+
public:
	Plane(std::string s); 

	void wearout(); //+
	size_t getResource(); //+
	void setWearoutPerTurn(float); //+
	size_t getPrice(); //+
	size_t getSpeed(); //+
	std::string getCurrentArp(); //+
	void setCurrentArp(std::string); //+
	size_t getTurnsToDest(); //+
	void setTurnsToDest(size_t); //+
	std::string getModel(); //+
	std::string getBoardNumber(); //+
	size_t getMaxRange(); //+
	size_t getCostPerKm(); //+
	size_t getMaxLoad(); //+
	void setIsOnFlight(bool);
	bool getIsOnFlight();
};

