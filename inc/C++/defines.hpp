/*!
*
*	\file		defines.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	November, 09 2019
*
*	\details	- Enable the use of ;
*					- BDD with bdd\n
*					- RNG with rng\n
*					- Arguments with arguments\n
*					- std::ifstream with reader\n
*					- std::ofstream with writer\n
*					- IOConfig with ioconfig\n
*
*/
#ifndef HEADER_CPP_DEFINES
#define HEADER_CPP_DEFINES

#include "C++/Timer.hpp"
//#include "C++/bdd.hpp"
#include "C++/Args.hpp"

#include "C++/DateTime.hpp"

#include "C++/Clock.hpp"
#include "C++/ConsoleTable.hpp"
#include "C++/Referenced.hpp"
#include "C++/IOConfig.hpp"

#include "C++/Map.hpp"

namespace mcd {
	/* Some defines */
		/*! \brief	Alias */
		using VI = std::vector<int>;
		/*! \brief	Alias */
		using vector_str = std::vector<std::string>;
		/*! \brief	Alias */
		using map_str = std::map<std::string, std::string>;
		/*! \brief	Alias */
		using pair_str = std::pair<std::string, std::string>;
	/****************/

	/*! \brief	A struct to define \b Contraption attributes */
	struct ContraptionAttr{
		/*! Width */
		double64_t w = 0;
		/*! Height */
		double64_t h = 0;
		/*! Angle */
		double64_t angle = 0;
	};

	/*! \brief	Directions to move */
	enum class Direction {
		UP = 0,
		DOWN = 1,
		RIGHT = 2,
		LEFT = 3,
		NONE = 4
	};
}

#endif //HEADER_CPP_DEFINES
