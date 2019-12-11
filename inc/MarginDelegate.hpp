/*!
*
*	\file		MarginDelegate.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Friday December, 06 2019 19:52:51
*	\modified	Friday December, 06 2019
*
*/
#ifndef HEADER_MARGIN_DELEGATE
#define HEADER_MARGIN_DELEGATE

#include "Widgets/Qt.hpp"

/*!
* \class	MarginDelegate
* \brief	An implementation of QItemDelegate with a margin
*/
class MarginDelegate : public QItemDelegate {
	/* Usefull or required defines */
		Q_OBJECT
	/* Members of MarginDelegate */
	public:
		/* Constructors & Destructor of MarginDelegate */
			/*! \brief	The constructor of the class */
			MarginDelegate(int margin, QObject* parent = nullptr);
			virtual ~MarginDelegate();

	protected:
		/* Others members of MarginDelegate */
			void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

	/* Atttributes of MarginDelegate */
	private:
		/* Local */
			int _margin;
};

#endif //HEADER_MARGIN_DELEGATE
