/*!
*
*	\file		files.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	August, 19 2018
*
*/
#ifndef HEADER_CPP_FILES
#define HEADER_CPP_FILES

#include <fstream>
#include "C++/convert.hpp"

namespace mcd {
	/*!
	* \brief	Format a given \a line for files
	*		\param[in,out]		line		The line to format
	*
	*		\return			void
	*/
	void fileFormat(std::string& line);

	/*!
	* \brief	Return true if the file exists
	*		\param[in]		path		The path to the file
	*/
	bool fileExists(const std::string& path);

	/*!
	* \brief	Get the file size
	*		\param[in]		path		The path to the file
	*
	*		\return			Return the size of the file
	*/
	size_t getFileSize(const std::string& path);

	/*!
	* \brief	Get all the lines in a given file
	*		\param[in]		input		The opened ifstream
	*
	*		\return			Return a vector which contains the file's lines
	*/
	std::vector<std::string> getlines(std::ifstream& input);

	/*!
	* \brief	Write all the lines in a given file
	*		\param[in]		output		The opened ofstream
	*		\param[in]		lines		The lines to write
	*
	*		\return			\b true or \b false
	*/
	bool setlines(std::ofstream& output, const std::vector<std::string>& lines);

	/*! \brief	Define a global file reader */
	extern std::ifstream reader;

	/*! \brief	Define a global file writer */
	extern std::ofstream writer;
}

#endif //HEADER_CPP_FILES
