/*!
*
*	\file		ConsoleTable.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	August, 16 2018
*
*/
#ifndef HEADER_CPP_CONSOLE_TABLE
#define HEADER_CPP_CONSOLE_TABLE

#include "C++/includes.hpp"

namespace mcd {
	/*!
	* \class	ConsoleTable
	* \brief	A class to print a table in the console
	*/
	class ConsoleTable{
		public:
			ConsoleTable();

			void headers(std::vector<std::string> h);

			void lines(std::vector<std::vector<std::string>> ls){
				for(auto l : ls){
					this->line(l);
				}
			}
			void line(std::vector<std::string> l);

			friend std::ostream& operator<<(std::ostream& str, ConsoleTable& t);

		private:
			std::vector<std::vector<std::string>> table;
			std::map<std::string, std::string> tableCars;
	};
}

#endif //HEADER_CPP_CONSOLE_TABLE
