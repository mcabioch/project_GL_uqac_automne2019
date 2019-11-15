#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	centerLayout(nullptr),
	center(nullptr),

	_tab(nullptr),
	_weekdays()
{
	/* Base */
		center = new QWidget;
		centerLayout = new QVBoxLayout;

		this->setWindowTitle("Planning Generator");
		this->setCentralWidget(center);

		center->setLayout(centerLayout);

		this->showMaximized();
	/********/

	_weekdays.push_back("Monday");
	_weekdays.push_back("Tuesday");
	_weekdays.push_back("Wednesday");
	_weekdays.push_back("Thursday");
	_weekdays.push_back("Friday");
	_weekdays.push_back("Saturday");
	_weekdays.push_back("Sunday");

	_tab = new QTabWidget();

	std::ifstream reader;
	reader.open("res/test.profile");
	if(reader){
		Globals globals;
		reader >> globals;
		reader.close();

		initGeneralTab(_tab, globals);
	} else {
		initGeneralTab(_tab);
	}

	initTeamTab(_tab);
	initPlanningTab(_tab);

	centerLayout->addWidget(_tab);
}

MainWindow::~MainWindow(){
	deleteGeneralTab(_tab);
	deleteTeamTab(_tab);
	deletePlanningTab(_tab);

	deletePtr(_tab);

	deletePtr(centerLayout);
	deletePtr(center);
}
