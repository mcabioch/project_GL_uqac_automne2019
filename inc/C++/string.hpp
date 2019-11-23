/*!
*
*	\file		string.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	September, 25 2019
*
*/
#ifndef HEADER_CPP_STRING
#define HEADER_CPP_STRING

#ifndef OS_WINDOWS
	#include <locale>
#else
	#include "boost/locale.hpp"
#endif

#include "C++/system.hpp"

#include "C++/RNG.hpp"
#include "C++/macro.hpp"

namespace mcd {
	enum CaractSet {
		ALPHA = 1,
		LOWER = 2,
		UPPER = 4,
		NUM   = 8,
		SPEC  = 16,
		READ  = 32,
		ALL   = 512
	};

	/*!
	* \brief	Explode a string in an array with the given caracter
	*		\param[in]		in			The string to cut
	*		\param[in]		separator	The separator caracter to cut \a in
	*
	*		\return			Return an array with the differents parts of the cut string
	*/
	std::vector<std::string> split(const std::string& in, char separator = ' ');
	/*!
	* \brief	Explode a string in an array with the given string
	*		\param[in]		in		The string to cut
	*		\param[in]		c		The separator string to cut \a in
	*
	*		\return			void
	*/
	std::vector<std::string> split(const std::string& in, const std::string& c);
	/*!
	* \brief	Explode a string in an array with the given separators
	*		\param[in]		in		The string to cut
	*		\param[in]		cars	The separators string to cut \a in
	*
	*		\return			void
	*/
	std::vector<std::string> split(const std::string& in, std::vector<std::string> cars);


	/*! \brief Alias for \b split */
		ALIAS_TEMPLATE_FUNCTION(explode, split)
	/***********/

	/*!
	* \brief	Delete all the too-much spaces in the given string
	*		\param[in,out]		in		The string to treat
	*
	*		\return			void
	*/
	void trim(std::string& in);

	/*!
	* \brief	Set the given interval to uppercase
	*		\param[in]		str		The string to treat
	*		\param[in]		begin	The begininng of the transformation
	*		\param[in]		end		The end of the transformation
	*
	*		\return			Return the changed string
	*/
	std::string uppercase(const std::string& str, std::string::iterator begin, std::string::iterator end);
	/*!
	* \brief	Set the given interval to lowercase
	*		\param[in]		str		The string to treat
	*		\param[in]		begin	The begininng of the transformation
	*		\param[in]		end		The end of the transformation
	*
	*		\return			Return the changed string
	*/
	std::string lowercase(const std::string& str, std::string::iterator begin, std::string::iterator end);

	/*!
	* \brief	Set the given string to uppercase
	*		\param[in]		str		The string to treat
	*
	*		\return			Return the changed string
	*/
	std::string uppercase(const std::string& str);
	/*!
	* \brief	Set the given string to lowercase
	*		\param[in]		str		The string to treat
	*
	*		\return			Return the changed string
	*/
	std::string lowercase(const std::string& str);

	/*!
	* \brief	Replace something by something else in a string using regex_replace
	*		\param[in]		str				The string to treat
	*		\param[in]		from			The string to replace
	*		\param[in]		to				The string to use to replace
	*		\param[in]		regex			\b true or \b false, \b true if \a from is a regex
	*		\param[in]		word			\b true or \b false, \b true if only have to replace complete words and not some parts
	*		\param[in]		insensitive		\b true or \b false
	*
	*		\return			Return the changed string
	*/
	std::string replace(const std::string& str, const std::string& from, const std::string& to, bool regex = false, bool word = false, bool insensitive = false);

	/*!
	* \brief	Create a random string
	*		\param[in]		nb		The number of caracters
	*		\param[in]		flags	The set of caracters to use
	*
	*		\return			Return the rand string
	*/
	std::string randStr(size_t nb, unsigned short flags = CaractSet::ALL);

	/*!
	* \brief	Count the number of appearances
	*		\param[in]			text			The text to read
	*		\param[in]			c				The caracter to find
	*		\return				Return number of appearances
	*/
	size_t count(const std::string& text, char c);

	/*!
	* \brief	Return all occurences of a regex in a string
	*		\param[in]			str_regex		The shape of the regex
	*		\param[in]			str				The string in which to search
	*		\param[in]			insensitive		\b true or \b false to enable/disablecase sensitive
	*		\return				Return a vector of string with the occurences
	*/
	std::vector<std::vector<std::string>> getall(const std::string& str_regex, const std::string& str, bool insensitive = false);

	/*!
	* \brief	Replace all the accents of a string
	*		\param[in]			str				The string in which to replace
	*		\return				Return the string without any accents
	*/
	std::string removeAccents(const std::string& str);
}

#endif //HEADER_CPP_STRING
