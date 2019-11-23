/*!
*
*	\file		Clock.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	August, 19 2018
*
*/
#ifndef HEADER_CPP_CLOCK
#define HEADER_CPP_CLOCK

#include "C++/includes.hpp"

namespace mcd {
	/*!
	* \class	Clock
	* \brief	A clock to measure the elapsed time
	*/
	class Clock {
		public:
			/* Constructor */
			Clock();

			/* Getters */
			/*!
			* \brief	Get time elapsed
			*		\return			Return time elapsed since the clock started in microseconds
			*/
			double64_t getElapsed();
			/*!
			* \brief	Get the time start
			*		\return			Return the start time since last clock start in microseconds
			*/
			double64_t getStart()const { return static_cast<double64_t>(m_start.time_since_epoch().count()); }

			/* Others */
			/*!
			* \details Start the clock
			*/
			void start();
			/*!
			* \details Restart the clock
			*/
			void restart();

		protected:
			std::chrono::high_resolution_clock::time_point m_start;
			bool started;
	};
}

#endif //HEADER_CPP_CLOCK
