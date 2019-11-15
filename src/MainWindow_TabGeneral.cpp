#include "MainWindow.h"

void MainWindow::initGeneralTab(QTabWidget* tabWidget){
/* New */
	_g_tab = new QWidget();
	_g_lay = new QVBoxLayout();

	_g_daysChoice = new QVBoxLayout();
	_g_checkAllLay = new QHBoxLayout();
	_g_allCheckbox = new QCheckBox("Check all");
	_g_checkDays = new QHBoxLayout();

	_g_minTimeLay = new QHBoxLayout();
	_g_minTimeEdit = new QTimeEdit();
	_g_minTimeLabel = new QLabel("Minimum hour to start : ");

	_g_maxTimeLay = new QHBoxLayout();
	_g_maxTimeEdit = new QTimeEdit();
	_g_maxTimeLabel = new QLabel("Maximum hour to stop : ");

	_g_defaultHoursLay = new QHBoxLayout();
	_g_defaultHoursEdit = new QDoubleSpinBox();
	_g_defaultHoursLabel = new QLabel("Default hours per week : ");

	_g_toolBar = new QToolBar();
/*******/

/* Add */
	_g_minTimeLay->addWidget(_g_minTimeLabel);
	_g_minTimeLay->addWidget(_g_minTimeEdit);
	_g_minTimeLay->addItem(new QHSpacerItem());

	_g_maxTimeLay->addWidget(_g_maxTimeLabel);
	_g_maxTimeLay->addWidget(_g_maxTimeEdit);
	_g_maxTimeLay->addItem(new QHSpacerItem());

	_g_defaultHoursLay->addWidget(_g_defaultHoursLabel);
	_g_defaultHoursLay->addWidget(_g_defaultHoursEdit);
	_g_defaultHoursLay->addItem(new QHSpacerItem());

	for(auto& weekday : _weekdays){
		_g_daysCheckboxes[weekday] = new QCheckBox(weekday);
		_g_checkDays->addWidget(_g_daysCheckboxes[weekday]);
	}
	_g_checkDays->addItem(new QHSpacerItem());

	_g_checkAllLay->addWidget(_g_allCheckbox);

	_g_daysChoice->addLayout(_g_checkAllLay);
	_g_daysChoice->addLayout(_g_checkDays);

	_g_lay->addLayout(_g_daysChoice);
	_g_lay->addLayout(_g_defaultHoursLay);
	_g_lay->addLayout(_g_minTimeLay);
	_g_lay->addLayout(_g_maxTimeLay);

	_g_lay->addItem(new QVSpacerItem());
	_g_tab->setLayout(_g_lay);

	tabWidget->addTab(_g_tab, "General");

	this->addToolBar(_g_toolBar);
/*******/

/* Toolbar */
	const QIcon saveIcon = QIcon("./res/icons/save-icon.png");
	QAction* saveAct = new QAction(saveIcon, tr("&Save"), this);
	saveAct->setStatusTip(tr("Save General and Team"));

	const QIcon generateIcon = QIcon("./res/icons/gen-icon.png");
	QAction* genAct = new QAction(generateIcon, tr("&Generate the planning"), this);
	genAct->setStatusTip(tr("Generate the planning"));

	_g_toolBar->addAction(saveAct);
	_g_toolBar->addAction(genAct);

	_g_toolBar->setMovable(false);
	_g_toolBar->setFloatable(false);
/***********/

	_g_defaultHoursEdit->setMinimum(0);

	connect(_g_allCheckbox, SIGNAL(stateChanged(int)), this, SLOT(generalAllCheckstate(int)));

	connect(saveAct, SIGNAL(triggered()), this, SLOT(generalSaveDatas()));
	connect(genAct, SIGNAL(triggered()), this, SLOT(generalCalculate()));
}

void MainWindow::initGeneralTab(QTabWidget* tabWidget, Globals initGlob){
	initGeneralTab(tabWidget);

/* Init values with initGlob */
	_g_minTimeEdit->setTime(getQTimeFromFloat(initGlob.startMin));
	_g_maxTimeEdit->setTime(getQTimeFromFloat(initGlob.endMax));
	_g_defaultHoursEdit->setValue(initGlob.nbHours);

	for(auto& day : initGlob.workedDays){
		_g_daysCheckboxes[day.c_str()]->setCheckState(Qt::Checked);
	}
	if(initGlob.workedDays.size() == 7){
		_g_allCheckbox->setCheckState(Qt::Checked);
	}
/*****************************/
}

void MainWindow::deleteGeneralTab(QTabWidget*/* tabWidget*/){
	deletePtr(_g_toolBar);

	deletePtr(_g_minTimeEdit);
	deletePtr(_g_minTimeLabel);
	deletePtr(_g_minTimeLay);

	deletePtr(_g_maxTimeEdit);
	deletePtr(_g_maxTimeLabel);
	deletePtr(_g_maxTimeLay);

	deletePtr(_g_defaultHoursEdit);
	deletePtr(_g_defaultHoursLabel);
	deletePtr(_g_defaultHoursLay);

	for(auto& dayCheckbox : _g_daysCheckboxes){
		deletePtr(dayCheckbox.second);
	}
	_g_daysCheckboxes.clear();

	deletePtr(_g_allCheckbox);

	deletePtr(_g_checkAllLay);
	deletePtr(_g_checkDays);

	deletePtr(_g_daysChoice);

	deletePtr(_g_lay);
	deletePtr(_g_tab);

	deletePtr(_g_toolBar);
}

void MainWindow::generalAllCheckstate(int state){
	Qt::CheckState cState;

	if(!state){
		_g_allCheckbox->setText("Check all");
		cState = Qt::Unchecked;
	} else {
		_g_allCheckbox->setText("Uncheck all");
		cState = Qt::Checked;
	}

	for(auto& weekday : _weekdays){
		_g_daysCheckboxes[weekday]->setCheckState(cState);
	}
}

void MainWindow::generalSaveDatas(){
	auto globals = translate();

	std::ofstream writer;

	writer.open("res/test.profile");
	writer << globals << std::endl;
	writer << teamMembers.size() << std::endl;
	for(auto& member : teamMembers){
		writer << member << std::endl;
	}
	writer.close();
}

void MainWindow::generalCalculate(){
	auto globals = translate();

	_planning.calculate(globals, teamMembers, _weekdays);
}

Globals MainWindow::translate(){
	Globals out;

	auto min = _g_minTimeEdit->time();
	auto max = _g_maxTimeEdit->time();

	out.startMin = static_cast<float>(min.hour()) + static_cast<float>(min.minute()) / 60.0 + static_cast<float>(min.second()) / 3600.0;
	out.endMax = static_cast<float>(max.hour()) + static_cast<float>(max.minute()) / 60.0 + static_cast<float>(max.second()) / 3600.0;
	out.nbHours = _g_defaultHoursEdit->value();
	for(auto& weekday : _weekdays){
		if(_g_daysCheckboxes[weekday]->checkState() != Qt::Unchecked){
			out.workedDays.push_back(weekday.toStdString());
		}
	}

	return out;
}

QTime MainWindow::getQTimeFromFloat(float time){
	int h = static_cast<int>(time);
	int m = static_cast<int>((time - h) * 60);
	int s = static_cast<int>((time - h - m/60.0) * 3600);

	return QTime(h, m, s);
}

void MainWindow::resetGeneralTab(QTabWidget* tabWidget){
	deleteGeneralTab(tabWidget);
	initGeneralTab(tabWidget);
}
