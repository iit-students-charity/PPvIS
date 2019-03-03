#pragma once
#include <vector>
#include <string>

class Map
{
private:
	std::vector <std::string> arps;
	std::vector <std::vector<size_t>> route;
	std::string file;
	bool isRandom;
public:
	Map(std::string = "");
	std::vector <std::string> getArps();
	std::vector <std::vector<size_t>> getRoute();
	size_t getRouteLength(std::string, std::string);
};

