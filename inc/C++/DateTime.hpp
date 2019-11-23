/*!
*
*	\file		DateTime.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	September, 26 2019
*
*/
#ifndef HEADER_CPP_DATETIME
#define HEADER_CPP_DATETIME

#include "C++/Date.hpp"
#include "C++/Time.hpp"

namespace mcd {
	/*!
	* \class	DateTime
	* \brief	A class to play with dates and times
	*/
	class DateTime : public Date, public Time {
		public:
			DateTime();
			explicit DateTime(const std::string& datetime);

			virtual ~DateTime(){}

			/* Getters */
			virtual std::string get(const std::string& format = "%Y-%m-%d %H:%M:%S")const override;

			/* Operators */
			friend bool operator<(const DateTime& a, const DateTime& b);
			friend bool operator==(const DateTime& a, const DateTime& b);

			friend bool operator!=(const DateTime& a, const DateTime& b);
			friend bool operator>(const DateTime& a, const DateTime& b);
			friend bool operator<=(const DateTime& a, const DateTime& b);
			friend bool operator>=(const DateTime& a, const DateTime& b);

		private:
			Date date;
			Time time;
	};

	std::ostream& operator<<(std::ostream& os, DateTime datetime);
}

#endif //HEADER_CPP_DATETIME
