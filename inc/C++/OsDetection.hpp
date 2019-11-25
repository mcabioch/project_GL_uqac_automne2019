/*!
*
*	\file		OsDetection.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Friday October, 04 2019 16:09:57
*	\modified	Friday October, 04 2019
*
*/
#ifndef HEADER_OS_DETECTION
#define HEADER_OS_DETECTION

#if defined(__FreeBSD__) ||\
	defined(__NetBSD__) ||\
	defined(__OpenBSD__) ||\
	defined(__bsdi__) ||\
	defined(__DragonFly__)
	#define OS_BSD
#elif defined(__gnu_linux__) ||\
	  defined(__linux__) ||\
	  defined(__linux) ||\
	  defined(linux) ||\
	  defined(__unix) ||\
	  defined(__unix__)
	#define OS_LINUX
#elif defined(__APPLE__) ||\
	  defined(__MACH__)
	#define OS_MAC
#elif defined(_WIN16) ||\
	  defined(_WIN32) ||\
	  defined(_WIN64) ||\
	  defined(__WIN32__) ||\
	  defined(__TOS_WIN__) ||\
	  defined(__WINDOWS__) ||\
	  defined(_WIN32_WCE) ||\
	  defined(MAKE_WINDOWS)
	#define OS_WINDOWS
#else
	#define OS_UNRECOGNIZE
#endif

#if defined(OS_WINDOWS) && !defined(MAKE_WINDOWS)
	#include <windows.h>
#elif defined(OS_LINUX)
	#include <unistd.h>
#endif

#include "C++/lowIncludes.hpp"

#endif //HEADER_OS_DETECTION
