/*!
*
*	\file		Path.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	July, 29 2018 16:12:40
*	\modified	September, 24 2019
*
*/
#ifndef HEADER_CPP_MAP_PATH
#define HEADER_CPP_MAP_PATH

#include "C++/includes.hpp"

namespace mcd {
	/*! \brief	A node for the path */
	struct PathfindingNode {
		size_t id;

		friend bool operator==(const PathfindingNode& a, const PathfindingNode& b){
			return (a.id == b.id);
		}
		friend bool operator<(const PathfindingNode& a, const PathfindingNode& b){
			return (a.id < b.id);
		}
		friend bool operator>(const PathfindingNode& a, const PathfindingNode& b){
			return (a.id > b.id);
		}

		friend bool operator!=(const PathfindingNode& a, const PathfindingNode& b){
			return !(a == b);
		}
		friend bool operator<=(const PathfindingNode& a, const PathfindingNode& b){
			return (a == b) || (a < b);
		}
		friend bool operator>=(const PathfindingNode& a, const PathfindingNode& b){
			return (a == b) || (a > b);
		}
	};

	/*!
	* \class	Path
	* \brief	A class to manage a path computed by the map
	*/
	class Path {
		/* Members of Path */
		public:
			/* Constructors & Destructor of Path */
				/*! \brief	The constructor of the class */
				Path();
				virtual ~Path();
			/* Getters of Path */
			
			/* Setters of Path */
			
			/* Statics of Path */
			
			/* Operators of Path */
			
			/* Friends of Path */
			
			/* Others members of Path */
				/*!
				* \brief	Put the next node in \a node
				*	\param[in,out]		node		The last node and thenext node
				*	\return				Return \b true or \b false
				*/
				bool next(PathfindingNode& node);

				/*! \brief	Return \b true if the path has a next node */
				bool hasNext()const;

				/*! \brief	Reset the path counter to restart the path */
				void reset();

				/*!
				* \brief	Push a new node in the path
				*	\param[in,out]		node		The node to push
				*	\return				Return void
				*/
				void push(const PathfindingNode& node){
					_path.push_back(node);
				}
				/*! \brief	Reverse the path */
				void reverse(){
					std::reverse(_path.begin(), _path.end());
				}

				/*! \brief	Return the number of node in the path */
				size_t size()const{
					return _path.size();
				}
				/*! \brief	Return the toal length of the path */
				double64_t length()const{
					return pathLength;
				}

		protected:
			/* Getters of Path */
			
			/* Setters of Path */
			
			/* Statics of Path */
			
			/* Friends of Path */
			
			/* Others members of Path */
			

		private:
		

		/* Atttributes of Path */
		public:
			/* Global */
			
			/* Local */
				#ifndef DOXYGEN_SHOULD_SKIP_THIS
					double64_t pathLength;
				#endif
				PathfindingNode start;
				PathfindingNode end;

		protected:
			/* Global */
			
			/* Local */
			

		private:
			/* Global */
			
			/* Local */
				size_t _index;

				std::vector<PathfindingNode> _path;

				#ifdef DOXYGEN_SHOULD_SKIP_THIS
					double64_t _pathLength;
				#endif
	};
}

#endif //HEADER_CPP_MAP_PATH
