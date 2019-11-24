#ifndef HEADER_GLOBALS
#define HEADER_GLOBALS

#include "Widgets/Qt.hpp"

class Globals {
	public:
		Globals() :
			startMin(0),
			endMax(0),
			nbHours(0),
			workedDays()
		{}

		Globals(float start, float end, float hours, const std::vector<std::string>& days) :
			startMin(start),
			endMax(end),
			nbHours(hours),
			workedDays(days)
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
