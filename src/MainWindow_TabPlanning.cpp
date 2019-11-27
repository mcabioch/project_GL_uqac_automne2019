#include "MainWindow.h"

void MainWindow::initPlanningTab(QTabWidget* tabWidget){
	_planningTab = new QMainWindow();
	_planTable = new QTableWidget();
	_planTab = new QMainWindow();
	_planCenter = new QWidget;
	_planLay = new QVBoxLayout();

	tabWidget->addTab(_planningTab, "Planning");

	_planningTab->setCentralWidget(_planCenter);
	_planCenter->setLayout(_planLay);

	_planTable->setColumnCount(7);
	QStringList headers/* = {"Hours"}*/;
	for(auto& day : mcd::arguments["weekdays"]){
		QStringList tmp(day.c_str());
		headers += tmp;
	}
	_planTable->setHorizontalHeaderLabels(headers);
	_planLay->addWidget(_planTable);

	for(size_t i = 0; i < 24; ++i){
		int pos = _planTable->rowCount();
		_planTable->insertRow(pos);
	}

	for(size_t i = 0; i < mcd::arguments["weekdays"].size(); ++i){
		for(int j = 0; j < 24; ++j){
			auto item = new QTableWidgetItem;
			_planItems.push_back(item);
			_planTable->setItem(j, static_cast<int>(i), item);
		}
	}
}

void MainWindow::deletePlanningTab(QTabWidget*/* tabWidget*/){
	mcd::deletePtr(_planningTab);
}

void MainWindow::resetPlanningTab(QTabWidget* tabWidget){
	deletePlanningTab(tabWidget);
	initPlanningTab(tabWidget);
}

void MainWindow::initPlanningTable() {
	_autoChange = true;

	for(size_t i = 0; i < mcd::arguments["weekdays"].size(); ++i){
		auto day = _planning.getDay(i);
		for(int j = 0; j < 24; ++j){
			bool found = false;
			for(const auto &e : day) {
				if(e.first <= static_cast<double>(j) && e.second >= static_cast<double>(j)){
					found = true;
				}
			}

			if(_planTable->item(j, static_cast<int>(i)) == nullptr){
				auto item = new QTableWidgetItem;
				_planItems.push_back(item);
				_planTable->setItem(j, static_cast<int>(i), item);
			}

			auto item = _planTable->item(j, static_cast<int>(i));
			if(found){
				item->setBackground(Qt::green);
			} else {
				item->setBackground(Qt::red);
			}
		}
	}

	_autoChange = false;

	/*connect(_teamTable, SIGNAL(cellClicked(int, int)), this, SLOT(updateSelectedMember(int, int)));
	connect(_teamTable, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(editMember(QTableWidgetItem*)));*/
}

void MainWindow::p_setAll(const Globals&, const std::vector<TeamMember>&, const Planning& pl){
	_planning = pl;
	initPlanningTable();
}
