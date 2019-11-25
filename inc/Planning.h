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
		~Planning(){}

		friend std::ostream& operator<<(std::ostream& os, const Planning& p);

		bool get()const { return true; }
	private:
		
};

#endif //HEADER_PLANNING
