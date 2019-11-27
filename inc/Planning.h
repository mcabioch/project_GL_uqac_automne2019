#ifndef HEADER_PLANNING
#define HEADER_PLANNING

#include "Widgets/Qt.hpp"

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
		Planning(const std::vector<std::vector<std::pair<double,double>>>& creneau);
		~Planning(){}

		friend std::ostream& operator<<(std::ostream& os, const Planning& p);

		std::vector<std::pair<double,double>> getDay(size_t day)const;
	private:
		std::vector<std::vector<std::pair<double,double>>> _creneau;
};

#endif //HEADER_PLANNING
