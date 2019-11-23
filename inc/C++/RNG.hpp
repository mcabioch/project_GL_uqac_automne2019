/*!
*
*	\file		RNG.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\date		May, 29 2018
*
*/
#ifndef HEADER_CPP_RNG
#define HEADER_CPP_RNG

#include <random>

namespace mcd {
	/*!
	* \class RNG
	* \brief	A class to simplify the use of random
	*/
	template<
		typename T,
		typename U
	>
	class RNG {
		public:
			RNG() : rd(), gen(rd()) {}

			/*!
			* \brief	The definition of the operator ()
			*		\param[in]		a		The first boundary
			*		\param[in]		b		The first boundary
			*
			*		\return			Return a random number between \a a and \a b
			*/
			T operator()(T a, T b){
				U dist(a, b);
				return dist(gen);
			}

		private:
			std::random_device rd;
			std::mt19937 gen;
	};

	#ifndef DOXYGEN_SHOULD_SKIP_THIS
		typedef RNG<int, std::uniform_int_distribution<>> Rng;
	#endif /* DOXYGEN_SHOULD_SKIP_THIS */

	/*!
	* \brief	Compute a random number in a computed range
	*		\param[in]		a		The boundary of the range
	*		\param[in]		b		The distance btween the boundaries
	*
	*		\return			Return a random value
	*/
	template<typename T, typename U = double>
	T rngRange(T a, U b = 0.1){
		Rng rng;

		return rng(static_cast<int>(a * (1.0 - b)), static_cast<int>(a * (1.0 + b)));
	}

	/*!
	* \brief	A global rng variable to compute random integers
	* \details	rng(\b int, \b int)
	*/
	extern Rng rng;
}

#endif //HEADER_CPP_RNG
