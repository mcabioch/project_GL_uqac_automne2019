/*!
*
*	\file		NotInstantiable.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Sunday September, 29 2019 11:20:17
*	\modified	Sunday September, 29 2019
*
*/
#ifndef HEADER_CPP_NOT_INSTANTIABLE
#define HEADER_CPP_NOT_INSTANTIABLE

namespace mcd {
	/*!
	* \class	NotInstantiable
	* \brief	Let a class being only an abstract class
	*/
	class NotInstantiable {
		/* Members of NotInstantiable */
		public:
			/* Constructors & Destructor of NotInstantiable */
				/*! \brief	The constructor of the class */
				NotInstantiable(){}
				virtual ~NotInstantiable(){}
			/* Others members of NotInstantiable */
				virtual void notInstantiable() final = 0;
	};
}

#endif //HEADER_CPP_NOT_INSTANTIABLE
