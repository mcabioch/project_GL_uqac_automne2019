/*!
*
*	\file		system.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	April, 24 2019
*
*/
#ifndef HEADER_CPP_SYSTEM
#define HEADER_CPP_SYSTEM

#include "C++/errors.hpp"

namespace mcd {
	/*! \brief	Use system in an IF and say if there is an error */
	void exec(const std::string& cmd, bool force = false);

	/*! \brief	Write a string in cout like in a server */
	void servLog(const std::string& str, bool server = false, const std::string& name = "Server");
}

#endif //HEADER_CPP_SYSTEM
