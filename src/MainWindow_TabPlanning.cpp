#include "MainWindow.h"

void MainWindow::initPlanningTab(QTabWidget* tabWidget){
	_planningTab = new QWidget();

	tabWidget->addTab(_planningTab, "Planning");
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
