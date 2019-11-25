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

	const QIcon deleteIcon = QIcon("./res/icons/delete-icon.png");
	QAction *deleteAct = new QAction(deleteIcon, tr("&Delete Member"), _teamTab);
	deleteAct->setStatusTip(tr("Delete a team member"));
	connect(deleteAct, SIGNAL(triggered()), this, SLOT(deleteMember()));

	_teamTable->setColumnCount(5);
	QStringList headers = { "Id", "First name", "Last name", "Nb of hours per week", "Days off"};
	_teamTable->setHorizontalHeaderLabels(headers);
	_teamTable->setColumnHidden(0, true);

	if(_api.isChef()){
		_teamToolBar->addAction(addAct);
		_teamToolBar->addAction(deleteAct);
	} else {
		_teamTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	}

	initTeamTable();

	_teamCenter->setLayout(_teamLay);
	_teamLay->addWidget(_teamTable);
}

bool operator==(const TeamMember& a, const int& b){ return (a.getId() == mcd::tos(b)); }

void MainWindow::initTeamTable() {
	_autoChange = true;

	_teamTable->clearContents();
	_teamTable->setRowCount(0);

	for(auto &e : teamMembers) {
		int pos = _teamTable->rowCount();
		QString doff = e.daysOffToQString();
		_teamTable->insertRow(pos);

		QTableWidgetItem *idItem = new QTableWidgetItem(e.getId().c_str());
		idItem->setFlags(idItem->flags() ^ Qt::ItemIsEditable);

		_teamTable->setItem(pos, AddMemberModal::Columns::ID, idItem);
		_teamTable->setItem(pos, AddMemberModal::Columns::FIRSTNAME, new QTableWidgetItem(e.getFirstName()));
		_teamTable->setItem(pos, AddMemberModal::Columns::LASTNAME, new QTableWidgetItem(e.getLastName()));
		_teamTable->setItem(pos, AddMemberModal::Columns::NBHOURS, new QTableWidgetItem(QString::number(e.getNbHours())));
		_teamTable->setItem(pos, AddMemberModal::Columns::DAYSOFF, new QTableWidgetItem(doff));
	}

	_autoChange = false;

	connect(_teamTable, SIGNAL(cellClicked(int, int)), this, SLOT(updateSelectedMember(int, int)));
	connect(_teamTable, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(editMember(QTableWidgetItem*)));
}

void MainWindow::updateSelectedMember(int row, int) {
	selectedMember = row;
}

void MainWindow::addMember() {
	AddMemberModal newMember(this, teamMembers, *_teamTable, _api);
	newMember.setModal(true);
	newMember.exec();
	initTeamTable();
}

void MainWindow::editMember(QTableWidgetItem *item) {
	if(_autoChange){
		return;
	}

	QTableWidgetItem *idItem = new QTableWidgetItem;
	idItem = _teamTable->item(item->row(), AddMemberModal::Columns::ID);

	int memberId = idItem->text().toInt();
	auto member = std::find(teamMembers.begin(), teamMembers.end(), memberId);

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
		
		default:
			break;
	}

		_api.saveMembers(teamMembers);
}
 
void MainWindow::deleteMember() {
	QMessageBox::StandardButton reply = QMessageBox::warning(this, "Confirmation", "Are you sure you want to delete this member ?", QMessageBox::No | QMessageBox::Yes);

	if(reply == QMessageBox::Yes) {
		_api.deleteMember(teamMembers[selectedMember].getId());
		teamMembers.erase(teamMembers.begin()+selectedMember);
		_teamTable->removeRow(selectedMember);
	}
}

void MainWindow::deleteTeamTab(QTabWidget*/* tabWidget*/){
	mcd::deletePtr(_teamToolBar);
	mcd::deletePtr(_teamLay);
	mcd::deletePtr(_teamTab);
}

void MainWindow::resetTeamTab(QTabWidget* tabWidget){
	deleteTeamTab(tabWidget);
	initTeamTab(tabWidget);
}

void MainWindow::t_setAll(const Globals&, const std::vector<TeamMember>& tm, const Planning&){
	teamMembers = tm;
	initTeamTable();
}
