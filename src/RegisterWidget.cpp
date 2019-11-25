#include "RegisterWidget.h"

#define RegisterWidget_INIT_LIST \
_username(nullptr),\
_password(nullptr),\
_passwordConf(nullptr),\
_checkAll(nullptr),\
_firstName(nullptr),\
_lastName(nullptr),\
_hoursPerWeek(nullptr),\
_t_daysCheckboxes(),\
\
centerLayout(nullptr)

RegisterWidget::RegisterWidget(bool passless, QWidget* parent) :
	QWidget(parent),
	RegisterWidget_INIT_LIST,
	_passless(passless)
{
	this->init();
}

RegisterWidget::RegisterWidget(const RegisterWidget& other) :
	QWidget(other.parentWidget()),
	RegisterWidget_INIT_LIST,
	_passless(other._passless)
{
	*this = other;
}

RegisterWidget& RegisterWidget::operator=(const RegisterWidget& other){
	this->init(&other);

	return *this;
}

RegisterWidget::~RegisterWidget(){
	mcd::logs(mcd::Logger::Debug, "RegisterWidget destroyed");
}

void RegisterWidget::init(const RegisterWidget*){
	centerLayout = new QVBoxLayout;

	auto formLayout = new QVBoxLayout();
	auto checkDaysOff = new QHBoxLayout();
	auto hoursPerWeekLay = new QHBoxLayout();

	_checkAll = new QCheckBox("Check all");
	_firstName = new QLineEdit();
	_lastName = new QLineEdit();
	_hoursPerWeek = new QDoubleSpinBox();

	_username = new QLineEdit;
	_password = new QLineEdit;
	_passwordConf = new QLineEdit;

	for(auto& weekday : mcd::arguments["weekdays"]){
		_t_daysCheckboxes[weekday] = new QCheckBox(weekday.c_str());
		checkDaysOff->addWidget(_t_daysCheckboxes[weekday]);
	}

	_password->setEchoMode(QLineEdit::Password);
	_passwordConf->setEchoMode(QLineEdit::Password);

	_firstName->setPlaceholderText("First name");
	_lastName->setPlaceholderText("Last name");
	_username->setPlaceholderText("Username");
	_password->setPlaceholderText("Password");
	_passwordConf->setPlaceholderText("Confirm Password");

	hoursPerWeekLay->addWidget(new QLabel("Number of hours per week : "));
	hoursPerWeekLay->addWidget(_hoursPerWeek);
	hoursPerWeekLay->addItem(new QHSpacerItem());

	formLayout->addWidget(new QLabel("Days off :"));
	formLayout->addWidget(_checkAll);
	formLayout->addLayout(checkDaysOff);
	formLayout->addLayout(hoursPerWeekLay);

	formLayout->addWidget(_firstName);
	formLayout->addWidget(_lastName);
	formLayout->addWidget(_username);

	if(!_passless){
		formLayout->addWidget(_password);
		formLayout->addWidget(_passwordConf);
	} else {
		_password->setText("secret");
		_passwordConf->setText("secret");
	}

	this->setLayout(formLayout);

	connect(_checkAll, SIGNAL(stateChanged(int)), this, SLOT(generalAllCheckstate(int)));

	mcd::logs(mcd::Logger::Debug, "RegisterWidget created");
}

void RegisterWidget::generalAllCheckstate(int state) {
	Qt::CheckState cState;

	if(!state){
		_checkAll->setText("Check all");
		cState = Qt::Unchecked;
	} else {
		_checkAll->setText("Uncheck all");
		cState = Qt::Checked;
	}

	for(auto& weekday : mcd::arguments["weekdays"]){
		_t_daysCheckboxes[weekday]->setCheckState(cState);
	}
}

std::string RegisterWidget::getDaysOff()const {
	std::string out = "";

	for(auto& checkbox : _t_daysCheckboxes){
		if(checkbox.second->checkState() != Qt::Unchecked) {
			if(out == ""){
				out = checkbox.first;
			} else {
				out += " ";
				out += checkbox.first;
			}
		}
	}

	return out;
}
