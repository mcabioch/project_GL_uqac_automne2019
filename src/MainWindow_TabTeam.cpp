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
	_teamTable->setProperty("class", "team");

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
	_teamTable->verticalHeader()->setVisible(false);
	_teamTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	_teamTable->setAttribute(Qt::WA_TranslucentBackground);
	_teamTable->setShowGrid(false);

	QPalette p(_teamTable->palette());
	quint8 r=170, g=170, b=170, a=85;
	p.setColor(QPalette::Base, QColor(QRgba64::fromRgba(r, g, b, a)));
	p.setColor(QPalette::Window, QColor(QRgba64::fromRgba(r, g, b, a)));

	_teamTable->setPalette(p);
	_teamTable->setAutoFillBackground(true);

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
	newMember.resize(560, 315);
	newMember.setStyleSheet(QString((cssReader("res/style.css")+cssReader("res/main.css")).c_str()));

	newMember.exec();
	initTeamTable();
}

void MainWindow::editMember(QTableWidgetItem *item) {
	if(_autoChange){
		return;
	}

	QTableWidgetItem *idItem = new QTableWidgetItem;
	idItem = _teamTable->item(item->row(), AddMemberModal::Columns::ID);

	std::string memberId = idItem->text().toStdString();
	auto member = std::find_if(teamMembers.begin(), teamMembers.end(), [memberId](const TeamMember& t){ return t.getId() == memberId; });
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

	_api.saveMember(*member);
}
 
void MainWindow::deleteMember() {
	QMessageBox warn;

	warn.setText("Are you sure you want to delete this member ?");
	warn.setIconPixmap(QIcon("res/imgs/care_icon.png").pixmap(64, 64));
	warn.setWindowTitle("Confirmation");
	warn.setStandardButtons(QMessageBox::Yes|QMessageBox::No);
	warn.setStyleSheet(QString((cssReader("res/style.css")+cssReader("res/main.css")).c_str()));

	int reply = warn.exec();

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
