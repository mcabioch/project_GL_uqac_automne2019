#include "IconedFormContainer.hpp"

#define INITLIST_IconedFormContainer \
_icon(nullptr),\
_field(nullptr),\
_str(""),\
_size(0)

IconedFormContainer::IconedFormContainer(QIcon* icon, int size, QWidget* field, const QString& str, QWidget* parent) :
	QWidget(parent),
	INITLIST_IconedFormContainer
{
	_icon = icon;
	_field = field;
	_str = str;
	_size = size;
	this->init();
}

IconedFormContainer::~IconedFormContainer(){}

IconedFormContainer::IconedFormContainer(const IconedFormContainer& other) :
	QWidget(other.parentWidget()),
	INITLIST_IconedFormContainer
{
	*this = other;
}

IconedFormContainer& IconedFormContainer::operator=(const IconedFormContainer& other) noexcept {
	if(this == &other){ return *this; }

	_icon = other._icon;
	_field = other._field;
	_str = other._str;
	_size = other._size;
	this->init();

	return *this;
}

void IconedFormContainer::init(){
	auto hl_lay = new QHBoxLayout;
	auto ic_lab = new QLabel;
	auto sizePolicy = QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

	ic_lab->setPixmap(_icon->pixmap(_size, _size));
	ic_lab->setProperty("class", "icon");

	setLayout(hl_lay);

	hl_lay->addWidget(ic_lab);
	if(_str != ""){
		auto label = new QLabel(_str);
		label->setSizePolicy(sizePolicy);
		hl_lay->addWidget(label);
	}
	hl_lay->addWidget(_field);

	ic_lab->setSizePolicy(sizePolicy);
	_field->setSizePolicy(sizePolicy);
	this->setSizePolicy(sizePolicy);
}

void IconedFormContainer::paintEvent(QPaintEvent *) {
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

