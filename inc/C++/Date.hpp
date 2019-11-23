/*!
*
*	\file		Date.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	September, 26 2019
*
*	\details	Formats disponibles afin de récupérer la date\n
*				\%A : Return the complete name of the day\n
*				\%a : Return the first 3 letters of the day\n
*				\%d : Return the number of the day in the month\n
*				\%j : Return the number of the day in the year\n
*				\%u : Return the number of the day in the week\n
*				\n
*				\%U : Return the number of the week in the year\n
*				\%V : return the number of the week in the month\n
*				\n
*				\%B : Return the complete name of the month\n
*				\%b : Return the first 3 letters of the month\n
*				\%m : Return the number of the month in the year\n
*				\n
*				\%C : Return the number of the century\n
*				\%s : Return the suffix to use with the century\n
*				\%Y : Return the number of the year\n
*				\%y : Return the last 2 numbers of the year\n
*
*/
#ifndef HEADER_CPP_DATE
#define HEADER_CPP_DATE

#include "C++/includes.hpp"

namespace mcd {
	/*!
	* \class	Date
	* \brief	A class to play with dates
	*/
	class Date {
		public:
			Date();
			explicit Date(const std::string& date);

			virtual ~Date(){}

			/* Getters */
			int day()const;
			std::string strDay()const;
			int weekDay()const;
			int yearDay()const;

			int monthWeek()const;
			int yearWeek()const;

			int month()const;
			std::string strMonth()const;

			int year()const;

			virtual std::string get(const std::string& format = "%Y-%m-%d")const;

			/* Setters */
			void set(const std::string& date);

		protected:
			void init();
			void reset();

		private:
			std::time_t _act;
			std::tm _dAct;

			std::string _date;
	};

	bool operator<(const Date& a, const Date& b);
	bool operator==(const Date& a, const Date& b);

	bool operator!=(const Date& a, const Date& b);
	bool operator>(const Date& a, const Date& b);
	bool operator<=(const Date& a, const Date& b);
	bool operator>=(const Date& a, const Date& b);

	std::ostream& operator<<(std::ostream& os, const Date& date);
}

#endif //HEADER_CPP_DATE
