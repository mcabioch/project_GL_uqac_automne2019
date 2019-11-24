#include "MainWindow.h"

#define MainWindow_INIT_LIST \
centerLayout(nullptr),\
center(nullptr),\
_tab(nullptr),\
_weekdays(),\
\
_g_tab(nullptr),\
_g_lay(nullptr),\
_g_daysChoice(nullptr),\
_g_checkAllLay(nullptr),\
_g_allCheckbox(nullptr),\
_g_checkDays(nullptr),\
_g_daysCheckboxes(),\
_g_minTimeLay(nullptr),\
_g_minTimeEdit(nullptr),\
_g_minTimeLabel(nullptr),\
_g_maxTimeLay(nullptr),\
_g_maxTimeEdit(nullptr),\
_g_maxTimeLabel(nullptr),\
_g_defaultHoursLay(nullptr),\
_g_defaultHoursEdit(nullptr),\
_g_defaultHoursLabel(nullptr),\
_g_toolBar(nullptr),\
\
_teamTab(nullptr),\
_teamCenter(nullptr),\
_teamLay(nullptr),\
_teamToolBar(nullptr),\
_teamTable(nullptr),\
selectedMember(0),\
teamMembers(),\
selectedTeamMembers(),\
\
_p_globals(),\
_p_teamMembers(),\
_planningTab(nullptr),\
_planningLay(nullptr),\
_planning()

MainWindow::MainWindow(Api& api, QWidget* parent) :
	QMainWindow(parent),
	MainWindow_INIT_LIST,
	_api(api)
{
	this->init();
}

MainWindow::MainWindow(const MainWindow& other) :
	QMainWindow(other.parentWidget()),
	MainWindow_INIT_LIST,
	_api(other._api)
{
	*this = other;
}

MainWindow& MainWindow::operator=(const MainWindow& other){
	this->init(&other);

	return *this;
}

MainWindow::~MainWindow(){
	mcd::logs(mcd::Logger::Debug, "MainWindow destroyed");

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

	mcd::logs(mcd::Logger::Debug, "MainWindow created");
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

	mcd::logs(mcd::Logger::Warn, "Add API connection here");

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
