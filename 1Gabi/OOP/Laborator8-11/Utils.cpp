#include "Utils.h"
#include <sstream>
#include <iostream>

std::vector<std::string> splitLine(std::string linie, char delim)
{

	std::stringstream ss(linie);
	std::string item;
	std::vector<std::string> elems;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}
