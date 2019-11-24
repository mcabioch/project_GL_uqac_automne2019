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
	auto mainLayout = new QGridLayout();

	_register = new RegisterWidget;
	_confirmButton = new QPushButton("Add");

	mainLayout->addWidget(_register, 0, 0);
	mainLayout->addItem(new QVSpacerItem(), 1, 0);
	mainLayout->addItem(new QHSpacerItem(), 0, 1);
	mainLayout->addWidget(_confirmButton, 1, 1);

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
	mcd::logs(mcd::Logger::Warn, "Add API connection here");
}

void AddMemberModal::addingNewMember(const std::string& id){
	//int memberId = static_cast<int>(_teamMembers.size())+1;
	int pos = _teamTable.rowCount();
	double hpw = _register->_hoursPerWeek->value();
	QString fn = _register->_firstName->text();
	QString ln = _register->_lastName->text();

	//_teamMembers.push_back(TeamMember(memberId, hpw, fn, ln, _daysOff));
	_teamMembers.push_back(TeamMember(id, hpw, fn, ln, _daysOff));

	QString doff = _teamMembers.back().daysOffToQString();
	_teamTable.insertRow(pos);

	//QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(memberId));
	QTableWidgetItem *idItem = new QTableWidgetItem(id.c_str());
	idItem->setFlags(idItem->flags() ^ Qt::ItemIsEditable);

	_teamTable.setItem(pos, Columns::ID, idItem);
	_teamTable.setItem(pos, Columns::FIRSTNAME, new QTableWidgetItem(fn));
	_teamTable.setItem(pos, Columns::LASTNAME, new QTableWidgetItem(ln));
	_teamTable.setItem(pos, Columns::NBHOURS, new QTableWidgetItem(QString::number(hpw)));
	_teamTable.setItem(pos, Columns::DAYSOFF, new QTableWidgetItem(doff));

	this->close();
}
