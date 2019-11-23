/*!
*
*	\file		time.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\date		October, 03 2019
*
*/
#ifndef HEADER_CPP_TIME_FUNC
#define HEADER_CPP_TIME_FUNC

#include <ctime>

#include "C++/strptime.h"

namespace mcd {
	/*!
	* \brief	Get the number of seconds since the Epoch
	*
	*		\return			Return the number of seconds
	*/
	std::time_t getSec();

	/*! \brief	Return the milliseconds since the Epoch */
	std::chrono::milliseconds getMilli();

	/*!
	* \brief	Sleep the thread during \a duration seconds
	*	\param[in]		duration		The time to sleep
	*	return			void
	*/
	void sleep(size_t duration);

	/*!
	* \brief	Sleep the thread during \a duration milliseconds
	*	\param[in]		duration		The time to sleep
	*	return			void
	*/
	void milliSleep(size_t duration);

	/*!
	* \brief	Sleep the thread during \a duration microseconds
	*	\param[in]		duration		The time to sleep
	*	return			void
	*/
	void microSleep(size_t duration);

	/*!
	* \brief	Sleep the thread during \a duration nanoseconds
	*	\param[in]		duration		The time to sleep
	*	return			void
	*/
	void nanoSleep(size_t duration);
}

#endif //HEADER_CPP_TIME_FUNCS
