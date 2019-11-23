#include "Planning.h"

Planning::Planning() :
	_freq(4),
	_planning(),
	_weekdays()
{}

std::string Planning::toCSV(const Globals&/* globals*/, const std::vector<TeamMember>& teamMembers, std::string separator){
	std::string csv = "";

	for(auto& day : _weekdays){
		csv += separator + day;
	}
	csv += "\n";

	for(auto& member : teamMembers){
		csv += member.getFirstName().toStdString() + " " + member.getLastName().toStdString();

		/*for(auto& slot : _planning[member.getId()][day]){
			for(auto& day : _weekdays){
				if(slot){
					csv += separator;
				} else {
					csv += separator + "?";
				}
			}
		}*/
	}

	return csv;
}

std::ostream& operator<<(std::ostream& os, const Planning& p){
	os << "Nb member : " << p._planning.size() << "\n";
	try {
		os << "Nb week days : " << p._planning.at(1).size() << "\n";
		os << "Nb hours a day : " << p._planning.at(1).at("Monday").size() << "\n";
	} catch(std::out_of_range& e){}

	return os;
}
