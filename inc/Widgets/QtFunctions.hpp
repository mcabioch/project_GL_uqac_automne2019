/*!
*
*	\file		QtFunctions.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\date		02 juin 2018
*
*/
#ifndef HEADER_QT_FUNCTIONS
#define HEADER_QT_FUNCTIONS

#include <QtWidgets>

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

/*! \brief An alias for Qt */
struct QtWindow {
	/*! Width */
	double_t w = 0;
	/*! Height */
	double_t h = 0;
	/*! Angle */
	double_t angle = 0;
};

/*!
* \brief Get the size of the desktop
* \return Return a QtWindow struct
*/
QtWindow getDesktopSize();

/*! \brief Get the width of the desktop */
size_t getDesktopWidth();
/*! \brief Get the height of the desktop */
size_t getDesktopHeight();

/*!
* \brief	Stick the \a a vector with the \a glue given
*		\param[in]		a			The array to stick
*		\param[in]		glue		The string to stick the array's elements
*
*		\return			Return a string of the array
*/
template<typename T>
std::string implode(const std::vector<T>& a, const std::string& glue = ""){
	std::string out{""};
	size_t size = a.size();
	size_t index = 0;

	for(auto& elem : a){
		std::stringstream tmp;
		tmp << elem;

		out += tmp.str();

		if(index+1 < size){
			out += glue;
		}

		index ++;
	}

	return out;
}

/*!
* \brief	Explode a string in an array with the given caracter
*		\param[in]		in			The string to cut
*		\param[in]		separator	The separator caracter to cut \a in
*
*		\return			Return an array with the differents parts of the cut string
*/
std::vector<std::string> explode(const std::string& in, char separator = ' ');
/*!
* \brief	Explode a string in an array with the given string
*		\param[in]		in		The string to cut
*		\param[in]		c		The separator string to cut \a in
*
*		\return			void
*/
std::vector<std::string> explode(const std::string& in, const std::string& c);
/*!
* \brief	Explode a string in an array with the given separators
*		\param[in]		in		The string to cut
*		\param[in]		cars	The separators string to cut \a in
*
*		\return			void
*/
std::vector<std::string> explode(const std::string& in, std::vector<std::string> cars);

/*!
* \brief	Get all the lines in a given file
*		\param[in]		input		The opened ifstream
*
*		\return			Return a vector which contains the file's lines
*/
std::vector<std::string> getlines(std::ifstream& input);

/*!
* \brief	Delete a pointer
*		\param[in,out]		pointer		The pointer to delete
*
*		\return			void
* \details	Delete \a pointer if is \b not \b equal to nullptr and \b not a joinable thread pointer.\n
* 			For a joinable thread pointer, it wait for the end of the function.\n
* 			After delete, it put the pointer to \b nullptr.
*/
template<typename T>
void deletePtr(T& pointer){
	if(pointer == nullptr){
		return;
	}

	delete pointer;
	pointer = nullptr;
}

struct replaceParams {
	bool regex;
	bool word;
	bool insensitive;
};

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
std::string replace(const std::string& str, const std::string& from, const std::string& to, const replaceParams& params = {false, false, false});

/*!
* \brief Read a Cascade Style Sheet and translate it for Qt
*	\param[in]		path		The path to the file
*	\return			Return the file contents as a string
*/
std::string cssReader(std::string path);

#endif //HEADER_QT_FUNCTIONS
