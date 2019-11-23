/*!
*
*	\file		strptime.h
*	\author		contributed to The NetBSD Foundation by Klaus Klein
*	\modified	October, 02 2019
*	\brief		Used to replace strptime function when compiling for Windows
*	\details	Copyright (c) 1997, 1998, 2005, 2008 The NetBSD Foundation, Inc.\n
* All rights reserved.
*
* This code was contributed to The NetBSD Foundation by Klaus Klein.
* Heavily optimised by David Laight
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
* 1. Redistributions of source code must retain the above copyright
*		notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*		notice, this list of conditions and the following disclaimer in the
*		documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
* ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
* PURPOSE ARE DISCLAIMED.	IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
* BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
* Inclusion in node-odbc note:
*
* This code was found here: http://social.msdn.microsoft.com/forums/en-US/vcgeneral/thread/25a654f9-b6b6-490a-8f36-c87483bb36b7 \n
* One user posted what looks to be a scaled down version of the NetBSD code
* but did not include any header with their work. Since it seems pretty obvious
* that the user took much of the code from NetBSD, that is why the NetBSD header 
* is displayed above.
*
*/
#ifndef _STRPTIME_H
#define _STRPTIME_H

#include "C++/string.hpp"

#ifdef OS_WINDOWS
	#define ALT_E          0x01
	#define ALT_O          0x02
	//#define LEGAL_ALT(x)       { if (alt_format & ~(x)) return (0); }
	#define LEGAL_ALT(x)       { ; }
	#define TM_YEAR_BASE   (1900)

	#include <ctype.h>
	#include <string.h>
	#include <time.h>
	#include <conio.h>

	#ifdef __cplusplus
	extern "C" {  
	#endif  

	char * strptime(const char *buf, const char *fmt, struct tm *tm);

	#ifdef __cplusplus
	}
	#endif

	static const char *day[7] = {
		 "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
		 "Friday", "Saturday"
	};

	static const char *abday[7] = {
		 "Sun","Mon","Tue","Wed","Thu","Fri","Sat"
	};

	static const char *mon[12] = {
		 "January", "February", "March", "April", "May", "June", "July",
		 "August", "September", "October", "November", "December"
	};

	static const char *abmon[12] = {
		 "Jan", "Feb", "Mar", "Apr", "May", "Jun",
		 "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
	};
	static const char *am_pm[2] = {
		 "AM", "PM"
	};
#endif

#endif
