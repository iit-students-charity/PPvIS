#include "stdafx.h"
#include "Map.h"
#include <fstream>

std::ifstream fin;
std::ofstream fout;

Map::Map(std::string fl)
{
	file = fl;
	std::vector<std::string> ct;
	std::string text;

	fin.open(file);
	getline(fin, text, '\n');
	for (size_t i = 0; i < text.size() + 1; i++)
	{
		std::string buff = "";
		while (text[i] != '\t' && text[i] != '\0')
		{
			buff += text[i];
			i++;
		}
		if (buff != "")
		{
			arps.push_back(std::string(buff));
		}
	}
	getline(fin, text, '\n');

	for (size_t i = 0; i < arps.size(); i++)
	{
		std::vector <size_t> bf;
		getline(fin, text, '\n');
		for (int j = 0; j < text.size(); j++)
		{
			std::string buff = "";
			while (text[j] != '\t' && text[j] != '\0')
			{
				buff += text[j];
				j++;
			}
			if (buff != "")
			{	
				bf.push_back(std::stoi(buff));
			}
		}
		route.push_back(bf);
	}
	fin.close();
}

std::vector <std::string> Map::getArps()
{
	return arps;
}

std::vector <std::vector<size_t>> Map::getRoute()
{
	return route;
}

size_t Map::getRouteLength(std::string a, std::string b)
{
	size_t i = 0;
	size_t j = 0;
	size_t length;
	while (arps[i] != a)
	{
		i++;
	}
	while (arps[j] != b)
	{
		j++;
	}
	length = route[i][j];
	return length;
}
