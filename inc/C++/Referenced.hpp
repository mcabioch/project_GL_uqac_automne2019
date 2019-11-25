/*!
*
*	\file		Referenced.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	July, 26 2018 08:47:36
*	\modified	September, 26 2019
*
*/
#ifndef HEADER_REFERENCED
#define HEADER_REFERENCED

#include "C++/includes.hpp"

namespace mcd {
	/*!
	* \class	Referenced
	* \brief	A class to have a reference to the class' pointer
	*/
	template<class C>
	class Referenced {
		/* Members of Referenced */
		public:
			/* Constructor of Referenced */
				explicit Referenced(C* her) :
					_her(*her)
				{}

		/* Atttributes of Referenced */
		protected:
			/* Local */
				C& _her;
	};

	template<class C>
	C& ref(C* obj){
		return *obj;
	}
	template<class C>
	C& ref(std::shared_ptr<C> obj){
		return *obj;
	}
}

#endif //HEADER_REFERENCED
