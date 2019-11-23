/*!
*
*	\file		Pathfinding.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	July, 30 2018 09:09:52
*	\modified	August, 15 2018
*
*/
#ifndef HEADER_CPP_PATHFINDING
#define HEADER_CPP_PATHFINDING

#include "C++/PathfindingProblem.hpp"

namespace mcd {
	/*!
	* \class	Pathfinding
	* \brief	A class to implement some pathfinding algorithms
	*/
	class Pathfinding {
		/* Members of Pathfinding */
		public:
			/* Constructors & Destructor of Pathfinding */
				/*!
				* \brief	The constructor of the class
				*	\param[in]		problem			The problem to solve
				*	\param[in]		start			The start point index
				*	\param[in]		end				The end point index
				*/
				Pathfinding(const PathfindingProblem& problem, const PathfindingNode& start, const PathfindingNode& end);
				virtual ~Pathfinding();
			/* Others members of Pathfinding */
				/*! \brief	Return the path to follow */
				Path getPath(){
					_path = this->createPath();

					_path.start = _start;
					_path.end = _end;

					return _path;
				}
				/*! \brief	Compute the path to follow */
				virtual Path createPath() = 0;

		/* Atttributes of Pathfinding */
		protected:
			/* Local */
				PathfindingProblem _problem;
				PathfindingNode _start;
				PathfindingNode _end;
				Path _path;
	};
}

#endif //HEADER_CPP_PATHFINDING
