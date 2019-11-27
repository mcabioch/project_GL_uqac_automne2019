#include "Planning.h"

Planning::Planning() :
	_creneau()
{}

Planning::Planning(const std::vector<std::vector<std::pair<double,double>>>& creneau) :
	_creneau(creneau)
{}

std::vector<std::pair<double,double>> Planning::getDay(size_t day)const {
	std::vector<std::pair<double,double>> out;

	for(auto& c : _creneau[day]){
		out.push_back(c);
	}

	return out;
}

std::ostream& operator<<(std::ostream& os, const Planning&/* p*/){
	

	return os;
}
