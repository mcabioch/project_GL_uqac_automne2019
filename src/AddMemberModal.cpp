#include "AddMemberModal.h"

AddMemberModal::AddMemberModal(QWidget *parent, const std::vector<QString> &_weekdays, std::vector<TeamMember> &_teamMembers, QTableWidget &_teamTable) :
    QDialog(parent),
    teamMembers(_teamMembers),
    teamTable(_teamTable)
{
    weekdays = _weekdays;
    this->setWindowTitle("New team member");
    initWindow();
}

void AddMemberModal::initWindow() {

    mainLayout = new QGridLayout();
    formLayout = new QVBoxLayout();
    checkDaysOff = new QHBoxLayout();
    hoursPerWeekLay = new QHBoxLayout();
    daysOffLabel = new QLabel("Days off :");
    checkAll = new QCheckBox("Check all");
    firstName = new QLineEdit();
    lastName = new QLineEdit();
    hoursPerWeekLabel = new QLabel("Number of hours per week : ");
    hoursPerWeek = new QDoubleSpinBox();
    confirmButton = new QPushButton("Add");

    firstName->setPlaceholderText("First name");
    lastName->setPlaceholderText("Last name");
    
    for(auto& weekday : weekdays){
		_t_daysCheckboxes[weekday] = new QCheckBox(weekday);
		checkDaysOff->addWidget(_t_daysCheckboxes[weekday]);
	}

    hoursPerWeekLay->addWidget(hoursPerWeekLabel);
    hoursPerWeekLay->addWidget(hoursPerWeek);
    hoursPerWeekLay->addItem(new QHSpacerItem());

    formLayout->addWidget(daysOffLabel);
    formLayout->addWidget(checkAll);
    formLayout->addLayout(checkDaysOff);
    formLayout->addWidget(firstName);
    formLayout->addWidget(lastName);
    formLayout->addLayout(hoursPerWeekLay);

    mainLayout->addLayout(formLayout, 0, 0);
    mainLayout->addItem(new QVSpacerItem(), 1, 0);
    mainLayout->addItem(new QHSpacerItem(), 0, 1);
    mainLayout->addWidget(confirmButton, 1, 1);

    this->setLayout(mainLayout);

    connect(checkAll, SIGNAL(stateChanged(int)), this, SLOT(generalAllCheckstate(int)));
    connect(confirmButton, SIGNAL(clicked()), this, SLOT(addNewMember()));
}

AddMemberModal::~AddMemberModal() {
    deletePtr(daysOffLabel);
    deletePtr(confirmButton);
    deletePtr(checkAll);
    deletePtr(firstName);
    deletePtr(lastName);
    deletePtr(hoursPerWeek);
    deletePtr(hoursPerWeekLabel);
    deletePtr(checkDaysOff);
    deletePtr(hoursPerWeekLay);
    deletePtr(formLayout);
    deletePtr(mainLayout);
}

void AddMemberModal::generalAllCheckstate(int state) {
    Qt::CheckState cState;

	if(!state){
		checkAll->setText("Check all");
		cState = Qt::Unchecked;
	} else {
		checkAll->setText("Uncheck all");
		cState = Qt::Checked;
	}

	for(auto& weekday : weekdays){
		_t_daysCheckboxes[weekday]->setCheckState(cState);
	}
}

void AddMemberModal::addNewMember() {
    for(auto& checkbox : _t_daysCheckboxes){
		if(checkbox.second->checkState() != Qt::Unchecked) {
            daysOff.push_back(checkbox.first);
        }
	}

    int memberId = static_cast<int>(teamMembers.size())+1;
    int pos = teamTable.rowCount();
    double hpw = hoursPerWeek->value();
    QString fn = firstName->text();
    QString ln = lastName->text();
    
    teamMembers.push_back(TeamMember(memberId, hpw, fn, ln, daysOff));
    
    QString doff = teamMembers.back().daysOffToQString();
    teamTable.insertRow(pos);

    QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(memberId));
    idItem->setFlags(idItem->flags() ^ Qt::ItemIsEditable);

    teamTable.setItem(pos, Columns::ID, idItem);
    teamTable.setItem(pos, Columns::FIRSTNAME, new QTableWidgetItem(fn));
    teamTable.setItem(pos, Columns::LASTNAME, new QTableWidgetItem(ln));
    teamTable.setItem(pos, Columns::NBHOURS, new QTableWidgetItem(QString::number(hpw)));
    teamTable.setItem(pos, Columns::DAYSOFF, new QTableWidgetItem(doff));

    this->close();
}