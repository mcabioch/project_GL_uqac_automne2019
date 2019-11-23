#ifndef HEADER_PLANNING
#define HEADER_PLANNING

#include <iostream>
#include <map>
#include <vector>

#include "Globals.h"
#include "TeamMember.h"

class Pause {
	public:
		Pause() :
			start(0),
			end(0)
		{}

		float start;
		float end;
};

class Planning {
	public:
		Planning();
		~Planning(){}

		friend std::ostream& operator<<(std::ostream& os, const Planning& p);

		std::string toCSV(const Globals& globals, const std::vector<TeamMember>& teamMembers, std::string separator = ",");

	private:
		

	private:
		float _freq;
		std::map<int, std::map<std::string, std::vector<bool>>> _planning;
		std::vector<std::string> _weekdays;
};

#endif //HEADER_PLANNING
