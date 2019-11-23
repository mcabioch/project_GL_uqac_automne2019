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

#include "C++/C++.hpp"

/*! \brief An alias for Qt */
using QtWindow = mcd::ContraptionAttr;

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
* \brief Read a Cascade Style Sheet and translate it for Qt
*	\param[in]		path		The path to the file
*	\return			Return the file contents as a string
*/
std::string cssReader(std::string path);

void clearLayout(QLayout* layout);

#endif //HEADER_QT_FUNCTIONS
