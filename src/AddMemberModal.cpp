#include "AddMemberModal.h"

AddMemberModal::AddMemberModal(QWidget *parent, const std::vector<QString> &weekdays, std::vector<TeamMember> &teamMembers, QTableWidget &teamTable) :
    QDialog(parent),

	_checkAll(nullptr),
	_firstName(nullptr),
	_lastName(nullptr),
	_hoursPerWeek(nullptr),
	_confirmButton(nullptr),

	_daysOff(),
	_weekdays(weekdays),
    _teamMembers(teamMembers),
    _teamTable(teamTable),

    _t_daysCheckboxes(),
    _workTime(0)
{
    init();
}

AddMemberModal::AddMemberModal(const AddMemberModal& other) :
	QDialog(other.parentWidget()),

	_checkAll(nullptr),
	_firstName(nullptr),
	_lastName(nullptr),
	_hoursPerWeek(nullptr),
	_confirmButton(nullptr),

	_daysOff(other._daysOff),
	_weekdays(other._weekdays),
    _teamMembers(other._teamMembers),
    _teamTable(other._teamTable),

    _t_daysCheckboxes(other._t_daysCheckboxes),
    _workTime(other._workTime)
{
	*this = other;
}

AddMemberModal& AddMemberModal::operator=(const AddMemberModal& other){
	init(&other);
	return *this;
}

void AddMemberModal::initWindow() {
    auto mainLayout = new QGridLayout();
    auto formLayout = new QVBoxLayout();
    auto checkDaysOff = new QHBoxLayout();
    auto hoursPerWeekLay = new QHBoxLayout();

    _checkAll = new QCheckBox("Check all");
    _firstName = new QLineEdit();
    _lastName = new QLineEdit();
    _hoursPerWeek = new QDoubleSpinBox();
    _confirmButton = new QPushButton("Add");

    _firstName->setPlaceholderText("First name");
    _lastName->setPlaceholderText("Last name");
    
    for(auto& weekday : _weekdays){
		_t_daysCheckboxes[weekday] = new QCheckBox(weekday);
		checkDaysOff->addWidget(_t_daysCheckboxes[weekday]);
	}

    hoursPerWeekLay->addWidget(new QLabel("Number of hours per week : "));
    hoursPerWeekLay->addWidget(_hoursPerWeek);
    hoursPerWeekLay->addItem(new QHSpacerItem());

    formLayout->addWidget(new QLabel("Days off :"));
    formLayout->addWidget(_checkAll);
    formLayout->addLayout(checkDaysOff);
    formLayout->addWidget(_firstName);
    formLayout->addWidget(_lastName);
    formLayout->addLayout(hoursPerWeekLay);

    mainLayout->addLayout(formLayout, 0, 0);
    mainLayout->addItem(new QVSpacerItem(), 1, 0);
    mainLayout->addItem(new QHSpacerItem(), 0, 1);
    mainLayout->addWidget(_confirmButton, 1, 1);

    this->setLayout(mainLayout);

    connect(_checkAll, SIGNAL(stateChanged(int)), this, SLOT(generalAllCheckstate(int)));
    connect(_confirmButton, SIGNAL(clicked()), this, SLOT(addNewMember()));
}

AddMemberModal::~AddMemberModal() {}

void AddMemberModal::init(const AddMemberModal*){
	this->setWindowTitle("New team member");
    initWindow();
}

void AddMemberModal::generalAllCheckstate(int state) {
    Qt::CheckState cState;

	if(!state){
		_checkAll->setText("Check all");
		cState = Qt::Unchecked;
	} else {
		_checkAll->setText("Uncheck all");
		cState = Qt::Checked;
	}

	for(auto& weekday : _weekdays){
		_t_daysCheckboxes[weekday]->setCheckState(cState);
	}
}

void AddMemberModal::addNewMember() {
    for(auto& checkbox : _t_daysCheckboxes){
		if(checkbox.second->checkState() != Qt::Unchecked) {
            _daysOff.push_back(checkbox.first);
        }
	}

    int memberId = static_cast<int>(_teamMembers.size())+1;
    int pos = _teamTable.rowCount();
    double hpw = _hoursPerWeek->value();
    QString fn = _firstName->text();
    QString ln = _lastName->text();
    
    _teamMembers.push_back(TeamMember(memberId, hpw, fn, ln, _daysOff));
    
    QString doff = _teamMembers.back().daysOffToQString();
    _teamTable.insertRow(pos);

    QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(memberId));
    idItem->setFlags(idItem->flags() ^ Qt::ItemIsEditable);

    _teamTable.setItem(pos, Columns::ID, idItem);
    _teamTable.setItem(pos, Columns::FIRSTNAME, new QTableWidgetItem(fn));
    _teamTable.setItem(pos, Columns::LASTNAME, new QTableWidgetItem(ln));
    _teamTable.setItem(pos, Columns::NBHOURS, new QTableWidgetItem(QString::number(hpw)));
    _teamTable.setItem(pos, Columns::DAYSOFF, new QTableWidgetItem(doff));

    this->close();
}
