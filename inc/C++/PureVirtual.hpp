/*!
*
*	\file		PureVirtual.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Saturday August, 11 2018 12:06:08
*	\modified	September, 24 2019
*
*/
#ifndef HEADER_PURE_VIRTUAL
#define HEADER_PURE_VIRTUAL

namespace mcd {
	/*!
	* \class	PureVirtual
	* \brief	A class to make some other to be abstract class
	*/
	class PureVirtual {
		/* Members of PureVirtual */
		public:
			/* Constructors & Destructor of PureVirtual */
				/*! \brief	The constructor of the class */
				PureVirtual();
				virtual ~PureVirtual();
			/* Others members of PureVirtual */
				virtual void PureVirtualMethod() final = 0;
	};
}

#endif //HEADER_PURE_VIRTUAL
