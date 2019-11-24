#include "MainWindow.h"

void MainWindow::initPlanningTab(QTabWidget* tabWidget){
	_planningTab = new QWidget();

	tabWidget->addTab(_planningTab, "Planning");

	connect(&_api, SIGNAL(getAll_ended(const Globals&, const std::vector<TeamMember>&, const Planning&)),
			this, SLOT(p_setAll(const Globals&, const std::vector<TeamMember>&, const Planning&)));
}

void MainWindow::deletePlanningTab(QTabWidget*/* tabWidget*/){
	mcd::deletePtr(_planningTab);
}

void MainWindow::resetPlanningTab(QTabWidget* tabWidget){
	deletePlanningTab(tabWidget);
	initPlanningTab(tabWidget);
}

void MainWindow::p_setAll(const Globals&, const std::vector<TeamMember>&, const Planning&){
	
}
