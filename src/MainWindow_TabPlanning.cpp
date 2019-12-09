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
	_planTable->setProperty("class", "planning");
	QStringList headers/* = {"Hours"}*/;
	for(auto& day : mcd::arguments["weekdays"]){
		QStringList tmp(day.substr(0, 3).c_str());
		headers += tmp;
	}
	_planTable->setHorizontalHeaderLabels(headers);
	_planLay->addWidget(_planTable);

	for(size_t i = 0; i < _nbHours; ++i){
		int pos = _planTable->rowCount();
		_planTable->insertRow(pos);
	}

	for(size_t i = 0; i < mcd::arguments["weekdays"].size(); ++i){
		for(int j = 0; j < static_cast<int>(_nbHours); ++j){
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

	_planTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	_planTable->setAttribute(Qt::WA_TranslucentBackground);
	_planTable->setShowGrid(false);
	_planTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	_planTable->verticalHeader()->setDefaultSectionSize(15);
	_planTable->setItemDelegate(new MarginDelegate(6, _planTable));

	for(size_t i = 0; i < mcd::arguments["weekdays"].size(); ++i){
		auto day = _planning.getDay(i);
		for(int j = 0; j < static_cast<int>(_nbHours); ++j){
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
				item->setBackground(QColor("#A68AC9AA"));
			} else {
				item->setBackground(Qt::transparent);
			}
		}
	}

	_autoChange = false;
}

void MainWindow::p_setAll(const Globals&, const std::vector<TeamMember>&, const Planning& pl){
	_planning = pl;
	initPlanningTable();
}
