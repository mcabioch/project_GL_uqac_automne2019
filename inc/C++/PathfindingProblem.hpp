/*!
*
*	\file		PathfindingProblem.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	July, 30 2018 09:16:58
*	\modified	August, 16 2018
*
*/
#ifndef HEADER_CPP_PATHFINDING_PROBLEM
#define HEADER_CPP_PATHFINDING_PROBLEM

#include "C++/PathfindingException.hpp"
#include "C++/Path.hpp"

namespace mcd {
	/*!
	* \class	PathfindingProblem
	* \brief	A class to group every pathfinding problems in one way to use it
	*/
	class PathfindingProblem {
		/* Members of PathfindingProblem */
		public:
			/* Constructors & Destructor of PathfindingProblem */
				/*! \brief	The constructor of the class */
				PathfindingProblem(std::vector<PathfindingNode> nodes, std::map<size_t, std::map<size_t, double64_t> > distances);
				PathfindingProblem(std::vector<PathfindingNode> nodes, std::map<size_t, std::map<size_t, double64_t> > distances, std::map<size_t, std::map<size_t, double64_t> > weights);
				virtual ~PathfindingProblem();

		/* Atttributes of PathfindingProblem */
		public:
			/* Local */
				std::vector<PathfindingNode> nodes;
				size_t nbNodes;

				std::map<size_t, std::map<size_t, double64_t> > distances;
				std::map<size_t, std::map<size_t, double64_t> > weights;
				std::map<size_t, std::map<size_t, bool> > computed;
	};
}

#endif //HEADER_CPP_PATHFINDING_PROBLEM
