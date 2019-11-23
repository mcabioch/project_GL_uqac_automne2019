#include "MainWindow.h"

#define MainWindow_INIT_LIST \
centerLayout(nullptr),\
center(nullptr),\
\
_tab(nullptr),\
_weekdays()\

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent),
	MainWindow_INIT_LIST
{
	this->init();
}

MainWindow::MainWindow(const MainWindow& other) :
	QMainWindow(other.parentWidget()),
	MainWindow_INIT_LIST
{
	*this = other;
}

MainWindow& MainWindow::operator=(const MainWindow& other){
	this->init(&other);

	return *this;
}

MainWindow::~MainWindow(){
	if(_tab == nullptr){
		return;
	}
}

void MainWindow::init(const MainWindow*){
	/* Base */
		center = new QWidget;
		centerLayout = new QVBoxLayout;

		this->setWindowTitle("Planning Generator");
		this->setCentralWidget(center);

		center->setLayout(centerLayout);

		this->showMaximized();
	/********/

	mcd::logs(mcd::Logger::Debug, "MainWindow created.");
}

void MainWindow::initWindow(){
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

		//initGeneralTab(_tab, globals);
	} else {
		//initGeneralTab(_tab);
	}

	//initTeamTab(_tab);
	//initPlanningTab(_tab);

	centerLayout->addWidget(_tab);
}
