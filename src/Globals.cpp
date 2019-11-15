#include "Globals.h"

std::ostream& operator<<(std::ostream& os, const Globals& g){
	os << "Minimum start hour : " << g.startMin << "\nMaximum stop hour  : " << g.endMax << "\nNb hours worked per week : " << g.nbHours << "\nWorked days ;\n";
	for(auto& day : g.workedDays){
		os << "\t- " << day << "\n";
	}

	return os;
}

std::ofstream& operator<<(std::ofstream& os, const Globals& g){
	os << g.startMin << " " << g.endMax << " " << g.workedDays.size() << "\n";
	for(auto& day : g.workedDays){
		os << day << "\n";
	}
	os << g.nbHours;

	return os;
}

std::ifstream& operator>>(std::ifstream& is, Globals& g){
	size_t size = 0;
	std::string str;

	is >> g.startMin >> g.endMax >> size;
	for(size_t i = 0; i < size; ++i){
		is >> str;
		g.workedDays.push_back(str);
	}
	is >> g.nbHours;

	return is;
}
