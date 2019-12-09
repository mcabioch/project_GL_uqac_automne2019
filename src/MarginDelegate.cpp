#include "MarginDelegate.hpp"

MarginDelegate::MarginDelegate(int margin, QObject* parent) :
	QItemDelegate(parent),
	_margin(margin)
{
	
}

MarginDelegate::~MarginDelegate(){}

void MarginDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const {
	QStyleOptionViewItem itemOption(option);

	// Make the 'drawing rectangle' smaller.
	itemOption.rect.adjust(_margin, 0, -_margin, 0);

	QItemDelegate::paint(painter, itemOption, index);
}
