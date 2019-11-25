/*!
*
*	\file		Time.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	September, 26 2019
*
*	\details	Formats disponibles afin de récupérer l'heure\n
*				\%H : Return the number of hours of the day between 00 and 24\n
*				\%I : Return the number of hours of the day between 00 and 12\n
*				\n
*				\%M : Return the number of minutes of the hour\n
*				\n
*				\%S : Return the number of seconds of the minute\n
*				\n
*				\%N : Return the number of milliseconds of the second\n
*				\n
*				\%P : Return AM or PM\n
*				\%p : Return am or pm\n
*
*/
#ifndef HEADER_CPP_TIME
#define HEADER_CPP_TIME

#include "C++/includes.hpp"

namespace mcd {
	/*!
	* \class	Time
	* \brief	A class to play with dates
	*/
	class Time {
		public:
			Time();
			explicit Time(const std::string& time);

			virtual ~Time(){}

			/* Getters */
			int hour()const;
			int minute()const;
			int second()const;
			int milli()const;

			virtual std::string get(const std::string& format = "%H:%M:%S")const;

			/* Setters */
			void set(const std::string& time);

		protected:
			void init();
			void reset();

		private:
			std::time_t _act;
			std::tm _dAct;
			int _milli;

			std::string _time;
	};

	bool operator<(const Time& a, const Time& b);
	bool operator==(const Time& a, const Time& b);

	bool operator!=(const Time& a, const Time& b);
	bool operator>(const Time& a, const Time& b);
	bool operator<=(const Time& a, const Time& b);
	bool operator>=(const Time& a, const Time& b);

	std::ostream& operator<<(std::ostream& os, const Time& time);
}

#endif //HEADER_CPP_TIME
