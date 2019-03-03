#pragma once
#include "Player.h"
class Bot :
	public Player
{
private:
	Map mp;
public:
	Bot(std::string, std::string);
	
	void action();
};

