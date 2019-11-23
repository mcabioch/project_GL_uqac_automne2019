/*!
*
*	\file		NotCopyable.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Monday August, 06 2018 06:55:14
*	\modified	September, 29 2019
*
*/
#ifndef HEADER_CPP_NOT_COPYABLE
#define HEADER_CPP_NOT_COPYABLE

namespace mcd {
	/*!
	* \class	NotCopyable
	* \brief	A class to let some other not to be copyable
	*/
	class NotCopyable {
		/* Members of NotCopyable */
		public:
			/* Constructors & Destructor of NotCopyable */
				/*! \brief	The constructor of the class */
				NotCopyable(){}
				virtual ~NotCopyable(){}

		private:
				/*! \brief	The copy constructor of the class */
				NotCopyable(const NotCopyable&){}
				/*! \brief	The move constructor of the class */
				NotCopyable(const NotCopyable&&){}

				/*! \brief	The copy operator of the class */
				NotCopyable& operator=(const NotCopyable&) noexcept { return *this; }
				/*! \brief	The move operator of the class */
				NotCopyable& operator=(const NotCopyable&&) noexcept { return *this; }

	};
}

#endif //HEADER_CPP_NOT_COPYABLE
