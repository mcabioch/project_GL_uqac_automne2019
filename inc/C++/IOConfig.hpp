/*!
*
*	\file		IOConfig.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Saturday January, 19 2019 17:09:41
*	\modified	September, 24 2019
*
*/
#ifndef HEADER_IOCONFIG
#define HEADER_IOCONFIG

#include "C++/includes.hpp"

namespace mcd {
	/*!
	* \class	IOConfig
	* \brief	A class to configure inputs and outputs
	*/
	class IOConfig {
		/* Usefull or required defines */
			typedef std::numeric_limits<double> dbl;
		/* Members of IOConfig */
		public:
			/* Constructors & Destructor of IOConfig */
				/*! \brief	The constructor of the class */
				IOConfig();
				virtual ~IOConfig();
	};
}

#endif //HEADER_IOCONFIG
