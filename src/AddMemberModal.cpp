#include "AddMemberModal.h"

AddMemberModal::AddMemberModal(QWidget *parent, std::vector<TeamMember> &teamMembers, QTableWidget &teamTable, Api& api) :
	QDialog(parent),

	_register(nullptr),
	_confirmButton(nullptr),

	_daysOff(),
	_teamMembers(teamMembers),
	_teamTable(teamTable),
	_api(api)
{
	init();
}

AddMemberModal::AddMemberModal(const AddMemberModal& other) :
	QDialog(other.parentWidget()),

	_register(nullptr),
	_confirmButton(nullptr),

	_daysOff(other._daysOff),
	_teamMembers(other._teamMembers),
	_teamTable(other._teamTable),
	_api(other._api)
{
	*this = other;
}

AddMemberModal& AddMemberModal::operator=(const AddMemberModal& other){
	init(&other);
	return *this;
}

void AddMemberModal::initWindow() {
	auto mainLayout = new QVBoxLayout();
	auto mainWidget = new QWidget();
	auto lay = new QVBoxLayout();
	auto inlay = new QHBoxLayout();

	auto vl_left = new QVBoxLayout();
	auto vl_right = new QVBoxLayout();

	int iconSize = 18;

	_register = new RegisterWidget;
	_confirmButton = new QPushButton("Add");

	_confirmButton->setProperty("class", "main-button");

	vl_left->addWidget(new IconedFormContainer(new QIcon("res/imgs/user_icon.png"), iconSize, _register->_firstName));
	vl_left->addWidget(new IconedFormContainer(new QIcon("res/imgs/user_icon.png"), iconSize, _register->_lastName));
	vl_left->addWidget(new IconedFormContainer(new QIcon("res/imgs/user_icon.png"), iconSize, _register->_username));
	vl_left->addWidget(new IconedFormContainer(new QIcon("res/imgs/pass_icon.png"), iconSize, _register->_password));
	vl_left->addWidget(new IconedFormContainer(new QIcon("res/imgs/pass_icon.png"), iconSize, _register->_passwordConf));

	vl_right->addWidget(new IconedFormContainer(new QIcon("res/imgs/clock_icon.png"), iconSize, _register->_hoursPerWeek, "Hours/week "));
	vl_right->addWidget(new IconedFormContainer(new QIcon("res/imgs/dayoff_icon.png"), iconSize, _register->_checkAll, "Days off "));
	for(auto weekday : mcd::arguments["weekdays"]){
		vl_right->addWidget(_register->_t_daysCheckboxes[weekday]);
	}

	inlay->addItem(new QHSpacerItem());
	inlay->addLayout(vl_left);
	inlay->addItem(new QHSpacerItem());
	inlay->addLayout(vl_right);
	inlay->addItem(new QHSpacerItem());

	lay->addItem(new QVSpacerItem());
	lay->addLayout(inlay);
	lay->addWidget(_confirmButton);
	lay->addItem(new QVSpacerItem());

	mainWidget->setLayout(lay);
	mainLayout->addWidget(mainWidget);
	this->setLayout(mainLayout);

	connect(_confirmButton, SIGNAL(clicked()), this, SLOT(addNewMember()));
	connect(&_api, SIGNAL(signin_ended(const std::string&)), this, SLOT(addingNewMember(const std::string&)));
}

AddMemberModal::~AddMemberModal() {}

void AddMemberModal::init(const AddMemberModal*){
	this->setWindowTitle("New team member");
	initWindow();
}

void AddMemberModal::addNewMember() {
	for(auto& checkbox : _register->_t_daysCheckboxes){
		if(checkbox.second->checkState() != Qt::Unchecked) {
			_daysOff.push_back(checkbox.first.c_str());
		}
	}

	_api.signin(AuthUser(_register->_username->text().toStdString(), _register->_password->text().toStdString()),
				AuthMember(_register->_firstName->text().toStdString(), _register->_lastName->text().toStdString(),
							_register->getDaysOff(), _register->_hoursPerWeek->value()));
}

void AddMemberModal::addingNewMember(const std::string& id){
	double hpw = _register->_hoursPerWeek->value();
	QString fn = _register->_firstName->text();
	QString ln = _register->_lastName->text();

	_teamMembers.push_back(TeamMember(id, hpw, fn, ln, _daysOff));

	this->close();
}
