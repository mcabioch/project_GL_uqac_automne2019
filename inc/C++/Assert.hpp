/*!
*
*	\file		Assert.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Wednesday November, 13 2019 11:22:08
*	\modified	Wednesday November, 14 2019
*
*/
#ifndef HEADER_ASSERT
#define HEADER_ASSERT

#include "C++/AssertionException.hpp"

namespace mcd {
	struct AssertionLocationStruct {
		std::string file;
		std::string func;
		int line;
	};

	/*!
	* \class	Assert
	* \brief	My assert's implementation
	*/
	class Assert {
		/* Members of Assert */
		public:
			/* Constructors & Destructor of Assert */
				/*! \brief	The constructor of the class */
				Assert(){}
				virtual ~Assert(){}
			/* Operators of Assert */
				void operator()(bool expr, const AssertionLocationStruct& location, const std::string& msg);
	};

	extern Assert assertion;
	#define assert(EXPR) mcd::assertion(static_cast<bool>(EXPR), {__FILE__, __PRETTY_FUNCTION__, __LINE__}, #EXPR)
	#define trycatch_assert(EXPR, INSTEAD) \
	try { assert(EXPR);\
	} catch(const mcd::AssertionException& e){\
		std::cout << mcd::Color(mcd::Colors::LIGHT_YELLOW_F) << e.what() << mcd::Color(mcd::Colors::NORMAL) << std::endl;\
		INSTEAD;\
	}
}

#endif //HEADER_ASSERT
