#include "MainWindow.h"

void MainWindow::initPlanningTab(QTabWidget* tabWidget){
	_planningTab = new QWidget();

	tabWidget->addTab(_planningTab, "Planning");

	_p_globals.startMin = 6;
	_p_globals.endMax = 16.5;
	_p_globals.nbHours = 35;
	_p_globals.workedDays = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

	int id = 0;

	_p_teamMembers.push_back(TeamMember(id, 40, QString('a'+id), QString('A'+id), {"Monday"}));
	id++;
	_p_teamMembers.push_back(TeamMember(id, 0, QString('a'+id), QString('A'+id), {"Wednesday"}));
	id++;
	_p_teamMembers.push_back(TeamMember(id, 0, QString('a'+id), QString('A'+id), {"Saturday"}));

	mcd::logs(mcd::Logger::Debug, "----------- Planning test -----------\n");
	mcd::logs(mcd::Logger::Debug, "### Dataset\n", _p_globals, "\n", _p_teamMembers.size(), "\n");
	for(auto& teamMember : _p_teamMembers){
		mcd::logs(mcd::Logger::Debug, teamMember);
	}

	_planning.calculate(_p_globals, _p_teamMembers, _weekdays, {{12, 13.25}});
	mcd::logs(mcd::Logger::Warn, "Add API connection here");
	mcd::logs(mcd::Logger::Debug, "-------------------------------------\n");
}

void MainWindow::deletePlanningTab(QTabWidget*/* tabWidget*/){
	mcd::deletePtr(_planningTab);
}

void MainWindow::resetPlanningTab(QTabWidget* tabWidget){
	deletePlanningTab(tabWidget);
	initPlanningTab(tabWidget);
}
