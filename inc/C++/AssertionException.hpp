/*!
*
*	\file		AssertionException.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Wednesday November, 13 2019 11:20:22
*	\modified	Wednesday November, 14 2019
*
*/
#ifndef HEADER_ASSERTION_EXCEPTION
#define HEADER_ASSERTION_EXCEPTION

#include "C++/defines.hpp"

namespace mcd {
	/*!
	* \class	AssertionException
	* \brief	An exception thrown by my assert's implementation
	*/
	class AssertionException : public std::exception {
		/* Members of AssertionException */
		public:
			/* Constructors & Destructor of AssertionException */
				/*! \brief	The constructor of the class */
				explicit AssertionException(const std::string& explaination) throw();
				virtual ~AssertionException() throw();
			/* Others members of AssertionException */
				/*! \brief	Return the explaination of the exception */
				virtual const char* what() const throw(){
					return _explaination.c_str();
				}

		/* Atttributes of AssertionException */
		private:
			/* Local */
				std::string _explaination;
	};
}

#endif //HEADER_ASSERTION_EXCEPTION
