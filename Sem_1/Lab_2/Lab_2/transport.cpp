#include "stdafx.h"
#include <iostream>
#include "transport.h"

transp::Transport::Transport()
{
	maxSpeed = 0;
	maxLoad = 0;
	weight = 0;
}

void transp::Transport::set_maxSpeed(int maxSpeed)
{
	Transport::maxSpeed = maxSpeed;
}

unsigned int transp::Transport::get_maxSpeed()
{
	return transp::Transport::maxSpeed;
}

void transp::Transport::set_maxLoad(int maxLoad)
{
	Transport::maxLoad = maxLoad;
}

unsigned int transp::Transport::get_maxLoad()
{
	return maxLoad;
}

void transp::Transport::set_weight(int weight)
{
	Transport::weight = weight;
}

unsigned int transp::Transport::get_weight()
{
	return weight;
}

void transp::Transport::hit_the_road()
{
	std::cout << "Let's go!" << std::endl;
}


transp::Air_Transport::Air_Transport() : 
	transp::Transport::Transport()
{
	maxHeight = 0;
	haveEngine = false;
}

void transp::Air_Transport::set_maxHeight(int maxHeight)
{
	Air_Transport::maxHeight = maxHeight;
}

unsigned int transp::Air_Transport::get_maxHeight()
{
	return maxHeight;
}

void transp::Air_Transport::set_haveEngine(int maxLoad)
{
	Air_Transport::weight = weight;
}

bool transp::Air_Transport::get_haveEngine()
{
	return haveEngine;
}


transp::Ground_Transport::Ground_Transport() :
	transp::Transport::Transport()
{
	wheelsCount = 4;
	engineType = "diesel";
}

void transp::Ground_Transport::set_wheelsCount(unsigned int wheelsCount)
{
	Ground_Transport::wheelsCount = wheelsCount;
}

int transp::Ground_Transport::get_wheelsCount()
{
	return wheelsCount;
}

void transp::Ground_Transport::set_engineType(std::string engineType)
{
	Ground_Transport::engineType = engineType;
}

std::string transp::Ground_Transport::get_engineType()
{
	return engineType;
}


transp::Water_Transport::Water_Transport() :
	transp::Transport::Transport()
{
	crewCount = 2;
	isWomanOnBoard = false;
}

void transp::Water_Transport::set_crewCount(unsigned int crewCount)
{
	Water_Transport::crewCount = crewCount;
}

unsigned int transp::Water_Transport::get_crewCount()
{
	return crewCount;
}

void transp::Water_Transport::set_isWomanOnBoard(bool isWomanOnBoard)
{
	Water_Transport::isWomanOnBoard = isWomanOnBoard;
}

bool transp::Water_Transport::get_isWomanOnBoard()
{
	return isWomanOnBoard;
}


transp::Planes::Planes() : 
	transp::Air_Transport::Air_Transport()
{
	wingsCount = 1;
	isIFR = false;
}

void transp::Planes::set_wingCount(unsigned int wingsCount)
{
	Planes::wingsCount = wingsCount;
}

unsigned int transp::Planes::get_wingsCount()
{
	return wingsCount;
}

void transp::Planes::set_isIFR(bool isIFR)
{
	Planes::isIFR = isIFR;
}

bool transp::Planes::get_isIFR()
{
	return isIFR;
}

void transp::Planes::hit_the_road()
{
	std::cout << "Cleaar prop!" << std::endl;
}


transp::Helicopters::Helicopters() : 
	transp::Air_Transport::Air_Transport()
{
	screwCount = 1;
	chassisType = "wheels";
}

void transp::Helicopters::set_wingCount(unsigned int screwCount)
{
	Helicopters::screwCount = screwCount;
}

unsigned int transp::Helicopters::get_screwCount()
{
	return screwCount;
}

void transp::Helicopters::set_chassisType(std::string chassisType)
{
	Helicopters::chassisType = chassisType;
}

std::string transp::Helicopters::get_chassisType()
{
	return chassisType;
}

void transp::Helicopters::hit_the_road()
{
	std::cout << "*playing Fortunate Son and getting flashbacks*" <<
		std::endl;
}


transp::Trains::Trains() : 
	transp::Ground_Transport::Ground_Transport()
{
	trackGauge = 1524;
}

void transp::Trains::set_trackGauge(unsigned int trackGauge)
{
	Trains::trackGauge = trackGauge;
}

unsigned int transp::Trains::get_trackGauge()
{
	return trackGauge;
}

void transp::Trains::hit_the_road()
{
	std::cout << "*Choo-choo!*" << std::endl;
}


transp::Cars::Cars() : 
	transp::Ground_Transport::Ground_Transport()
{
	mantaincePricePerYear = 2000;
	isAutopilot = false;
}

void transp::Cars::set_mantaincePricePerYear(unsigned int mantaincePricePerYear)
{
	Cars::mantaincePricePerYear = mantaincePricePerYear;
}

unsigned int transp::Cars::get_mantaincePricePerYear()
{
	return mantaincePricePerYear;
}

void transp::Cars::set_isAutopilot(bool isAutopilot)
{
	Cars::isAutopilot = isAutopilot;
}

bool transp::Cars::get_isAutopilot()
{
	return isAutopilot;
}

void transp::Cars::hit_the_road()
{
	std::cout << "*Vroom-vroom*" << std::endl;
}


transp::Submarines::Submarines() : 
	transp::Water_Transport::Water_Transport()
{
	maxDepth = 200;
}

void transp::Submarines::set_maxDepth(unsigned int maxDepth)
{
	Submarines::maxDepth = maxDepth;
}

unsigned int transp::Submarines::get_maxDepth()
{
	return maxDepth;
}

void transp::Submarines::set_isYellow(bool isYellow)
{
	Submarines::isYellow = isYellow;
}

bool transp::Submarines::get_isYellow()
{
	return isYellow;
}

void transp::Submarines::hit_the_road()
{
	std::cout << "Blow ballast!" << std::endl;
}


transp::Ships::Ships() :
	transp::Water_Transport::Water_Transport()
{
	displacement = 20000;
	boardNumber = "A000AA";
}

void transp::Ships::set_displacement(unsigned int displacement)
{
	Ships::displacement = displacement;
}

unsigned int transp::Ships::get_displacement()
{
	return displacement;
}

void transp::Ships::set_boardNumber(std::string boardNumber)
{
	Ships::boardNumber = boardNumber;
}

std::string transp::Ships::get_boardNumber()
{
	return boardNumber;
}

void transp::Ships::hit_the_road()
{
	std::cout << "Full steam ahead!" << std::endl;
}
