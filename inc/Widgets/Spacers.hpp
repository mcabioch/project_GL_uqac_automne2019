/*!
*
*	\file		Spacers.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\date		09 juin 2018
*
*/
#ifndef HEADER_SPACERS
#define HEADER_SPACERS

#include <QtWidgets>

/*!
* \class	QHSpacerItem
* \brief	An implementation of QSpacerItem
*/
class QHSpacerItem : public QSpacerItem {
	public:
		/*! \brief	Create a QSpacerItem that expend horizontally */
		QHSpacerItem(int w = 0, int h = 0) : QSpacerItem(w, h, QSizePolicy::Expanding, QSizePolicy::Minimum){}
};

/*!
* \class	QVSpacerItem
* \brief	An implementation of QSpacerItem
*/
class QVSpacerItem : public QSpacerItem {
	public:
		/*! \brief	Create a QSpacerItem that expend vertically */
		QVSpacerItem(int w = 0, int h = 0) : QSpacerItem(w, h, QSizePolicy::Minimum, QSizePolicy::Expanding){}
};

#endif //HEADER_SPACERS
