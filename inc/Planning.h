#ifndef HEADER_PLANNING
#define HEADER_PLANNING

#include <iostream>
#include <map>
#include <vector>

#include "Globals.h"
#include "TeamMember.h"

struct Pause {
	float start;
	float end;
};

class Planning {
	public:
		Planning();
		~Planning(){}

		std::map<int, std::map<std::string, std::vector<bool>>> calculate(const Globals& globals,
																		  const std::vector<TeamMember>& teamMembers,
																		  const std::vector<QString>& weekdays,
																		  const std::vector<Pause>& pauses = {}
																		 );

		friend std::ostream& operator<<(std::ostream& os, const Planning& p);

		std::string toCSV(const Globals& globals, const std::vector<TeamMember>& teamMembers, std::string separator = ",");

	private:
		std::vector<std::pair<std::string, size_t>> getBestSlots(const Globals& globals,
																 const TeamMember& member,
																 const std::map<std::string, std::vector<bool>>& memberPlanning,
																 const std::map<std::string, std::vector<int>>& globalPlanning,
																 const std::vector<Pause>& pauses
																);
		bool isPause(float slot, const std::vector<Pause>& pauses);

	private:
		float _freq;
		std::map<int, std::map<std::string, std::vector<bool>>> _planning;
		std::vector<std::string> _weekdays;
};

#endif //HEADER_PLANNING
