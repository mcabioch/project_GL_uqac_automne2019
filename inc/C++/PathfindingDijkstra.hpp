/*!
*
*	\file		PathfindingDijkstra.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	July, 30 2018 11:12:40
*	\modified	September, 26 2019
*
*/
#ifndef HEADER_CPP_PATHFINDING_DIJKSTRA
#define HEADER_CPP_PATHFINDING_DIJKSTRA

#include "C++/Pathfinding.hpp"

namespace mcd {
	/*!
	* \class	PathfindingDijkstra
	* \brief	An implementation of the Dijkstra algorithm
	*/
	class PathfindingDijkstra : public Pathfinding {
		/* Members of PathfindingDijkstra */
		public:
			/* Constructors & Destructor of PathfindingDijkstra */
				/*!
				* \brief	The constructor of the class
				*	\param[in]		problem			The problem to solve
				*	\param[in]		start			The start point index
				*	\param[in]		end				The end point index
				*/
				PathfindingDijkstra(const PathfindingProblem& problem, const PathfindingNode& start, const PathfindingNode& end);
				virtual ~PathfindingDijkstra();
			/* Others members of PathfindingDijkstra */
				/*! \brief	Compute the path to follow */
				virtual Path createPath() override;

		private:
			void next();
			size_t littlest();
			std::vector<size_t> linked(size_t node);
			void constructPath(size_t node);

		/* Atttributes of PathfindingDijkstra */
		private:
			/* Local */
				std::map<size_t, bool> _visited;
				std::map<size_t, double64_t> _weights;
				std::map<size_t, bool> _computed;
				std::map<size_t, size_t> _previous;
	};
}

#endif //HEADER_CPP_PATHFINDING_DIJKSTRA
