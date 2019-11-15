#include "MainWindow.h"

void MainWindow::initTeamTab(QTabWidget* tabWidget){
	_teamTab = new QMainWindow();
	_teamCenter = new QWidget;
	_teamToolBar = new QToolBar();
	_teamTable = new QTableWidget();
	_teamLay = new QVBoxLayout();

	tabWidget->addTab(_teamTab, "Team");
	_teamTab->addToolBar(_teamToolBar);
	_teamToolBar->setFloatable(false);
	_teamToolBar->setMovable(false);
	_teamTab->setCentralWidget(_teamCenter);

	const QIcon addIcon = QIcon("./res/icons/add-icon.png");
	QAction *addAct = new QAction(addIcon, tr("&Add Member"), _teamTab);
	addAct->setStatusTip(tr("Create a new team member"));
	connect(addAct, &QAction::triggered, this, &MainWindow::addMember);
	_teamToolBar->addAction(addAct);

	/*const QIcon editIcon = QIcon("./res/icons/edit-icon.png");
	QAction *editAct = new QAction(editIcon, tr("&Edit Member"), _teamTab);
	editAct->setStatusTip(tr("Edit a team member"));
	connect(editAct, SIGNAL(triggered()), this, SLOT(editMember()));
	_teamToolBar->addAction(editAct);*/
	
	const QIcon deleteIcon = QIcon("./res/icons/delete-icon.png");
	QAction *deleteAct = new QAction(deleteIcon, tr("&Delete Member"), _teamTab);
	deleteAct->setStatusTip(tr("Delete a team member"));
	connect(deleteAct, SIGNAL(triggered()), this, SLOT(deleteMember()));
	_teamToolBar->addAction(deleteAct);

	_teamTable->setColumnCount(5);
	QStringList headers = { "Id", "First name", "Last name", "Nb of hours per week", "Days off"};
	_teamTable->setHorizontalHeaderLabels(headers);

	initTeamTable();

	_teamCenter->setLayout(_teamLay);
	_teamLay->addWidget(_teamTable);
}

bool operator==(const TeamMember& a, const int& b){ return (a.getId() == b); }

void MainWindow::initTeamTable() {
	for(auto &e : teamMembers) {
		_teamTable->setItem(_teamTable->rowCount() - 1, AddMemberModal::Columns::ID, new QTableWidgetItem(QString::number(e.getId())));
	}

	connect(_teamTable, SIGNAL(cellClicked(int, int)), this, SLOT(updateSelectedMember(int, int)));
	connect(_teamTable, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(editMember(QTableWidgetItem*)));
}

void MainWindow::updateSelectedMember(int row, int column) {
	selectedMember = row;
}

void MainWindow::addMember() {
	AddMemberModal newMember(this, _weekdays, teamMembers, *_teamTable);
	newMember.setModal(true);
	newMember.exec();
}

void MainWindow::editMember(QTableWidgetItem *item) {
	std::cout << "CHANGED" << std::endl;
	
	QTableWidgetItem *idItem = new QTableWidgetItem;
	idItem = _teamTable->item(item->row(), AddMemberModal::Columns::ID);

	int memberId = idItem->text().toInt();
	std::cout << "id: "<< memberId << std::endl;

	auto member = std::find(teamMembers.begin(), teamMembers.end(), memberId);

	std::cout << "MEMBER : " << *member << std::endl;

	switch(item->column()) {
		case AddMemberModal::Columns::FIRSTNAME :
			member->setFirstName(item->text());
			break;
		
		case AddMemberModal::Columns::LASTNAME :
			member->setLastName(item->text());
			break;
		
		case AddMemberModal::Columns::NBHOURS :
			member->setNbHours(item->text().toDouble());
			break;
		
		case AddMemberModal::Columns::DAYSOFF :
			member->setDaysOffFromQString(item->text());
	}
}
 
void MainWindow::deleteMember() {
	std::cout << "test2" << std::endl;

	QMessageBox::StandardButton reply = QMessageBox::warning(this, "Confirmation", "Are you sure you want to delete this member ?", QMessageBox::No | QMessageBox::Yes);

	if(reply == QMessageBox::Yes) {
		teamMembers.erase(teamMembers.begin()+selectedMember);
		_teamTable->removeRow(selectedMember);
	} else {
		std::cout<<"no"<<std::endl;
	}
}

void MainWindow::deleteTeamTab(QTabWidget* tabWidget){
	deletePtr(_teamToolBar);
	deletePtr(_teamLay);
	deletePtr(_teamTab);
}

void MainWindow::resetTeamTab(QTabWidget* tabWidget){
	deleteTeamTab(tabWidget);
	initTeamTab(tabWidget);
}

