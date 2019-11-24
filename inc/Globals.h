#ifndef HEADER_GLOBALS
#define HEADER_GLOBALS

#include "Widgets/Qt.hpp"

struct Globals {
	Globals() :
		startMin(0),
		endMax(0),
		nbHours(0),
		workedDays()
	{}

	float startMin;
	float endMax;
	float nbHours;
	std::vector<std::string> workedDays;
};

std::ostream& operator<<(std::ostream& os, const Globals& g);

std::ofstream& operator<<(std::ofstream& os, const Globals& g);
std::ifstream& operator>>(std::ifstream& is, Globals& g);

#endif //HEADER_GLOBALS
