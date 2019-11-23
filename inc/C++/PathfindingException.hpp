/*!
*
*	\file		PathfindingException.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	July, 30 2018 09:25:28
*	\modified	September, 25 2019
*
*/
#ifndef HEADER_CPP_PATHFINDING_EXCEPTION
#define HEADER_CPP_PATHFINDING_EXCEPTION

#include "C++/includes.hpp"

namespace mcd {
	/*!
	* \class	PathfindingException
	* \brief	All exceptions that could be thrown by the pathfinding algorithm
	*/
	class PathfindingException : public std::exception {
		/* Members of PathfindingException */
		public:
			enum PathfindingErrorCode {
				NONE,
				ARRIVED,
				LOST,
				OTHER
			};

			/* Constructors & Destructor of PathfindingException */
				/*! \brief	The constructor of the class */
				PathfindingException(PathfindingErrorCode error = PathfindingErrorCode::NONE, const std::string& explaination = "") throw();
				virtual ~PathfindingException() throw();

				PathfindingException(const PathfindingException& other) throw();
			/* Others members of PathfindingException */
				/*! \brief	Return the explaination of the exception */
				virtual const char* what() const throw(){
					return _explaination.c_str();
				}

				/*! \brief	Return the error code of the exception */
				PathfindingErrorCode getErrorCode() const throw(){
					return _error;
				}

				static void Arrived();
				static void Lost();

		/* Atttributes of PathfindingException */
		private:
			/* Local */
				PathfindingErrorCode _error;
				std::string _explaination;
	};
}

#endif //HEADER_CPP_PATHFINDING_EXCEPTION
