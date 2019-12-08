#include "MainWindow.h"

void MainWindow::initGeneralTab(QTabWidget* tabWidget){
/* New */
	_g_tab = new QWidget();
	_g_lay = new QHBoxLayout();
	auto vl_left = new QVBoxLayout();
	auto vl_right = new QVBoxLayout();

	_g_allCheckbox = new QCheckBox("Check all");
	_g_minTimeEdit = new QTimeEdit();
	_g_maxTimeEdit = new QTimeEdit();
	_g_defaultHoursEdit = new QDoubleSpinBox();

	_g_toolBar = new QToolBar();

	auto rightDefaultHours = new IconedFormContainer(new QIcon(""), 0, _g_defaultHoursEdit, "Default hours per week : ");
	auto rightMinHours = new IconedFormContainer(new QIcon(""), 0, _g_minTimeEdit, "Minimum hour to start : ");
	auto rightMaxHours = new IconedFormContainer(new QIcon(""), 0, _g_maxTimeEdit, "Maximum hour to stop : ");
/*******/

/* Styles */
	_g_tab->setAttribute(Qt::WA_TranslucentBackground);

	rightDefaultHours->setProperty("class", "right");
	rightMinHours->setProperty("class", "right");
	rightMaxHours->setProperty("class", "right");
/**********/

/* Add */
	vl_left->addWidget(new IconedFormContainer(new QIcon("res/imgs/work_icon.png"), 18, _g_allCheckbox, "Working days "));
	for(auto& weekday : mcd::arguments["weekdays"]){
		_g_daysCheckboxes[weekday] = new QCheckBox(weekday.c_str());
		vl_left->addWidget(_g_daysCheckboxes[weekday]);
	}

	vl_right->addItem(new QVSpacerItem());
	vl_right->addWidget(rightDefaultHours, 0, Qt::AlignRight);
	vl_right->addWidget(rightMinHours, 0, Qt::AlignRight);
	vl_right->addWidget(rightMaxHours, 0, Qt::AlignRight);
	vl_right->addItem(new QVSpacerItem());

	_g_lay->addItem(new QHSpacerItem());
	_g_lay->addLayout(vl_left);
	_g_lay->addLayout(vl_right);
	_g_lay->addItem(new QHSpacerItem());

	_g_tab->setLayout(_g_lay);

	tabWidget->addTab(_g_tab, "General");

	this->addToolBar(Qt::LeftToolBarArea, _g_toolBar);
/*******/

/* Toolbar */
	const QIcon saveIcon = QIcon("./res/icons/save-icon.png");
	_saveAct = new QAction(saveIcon, tr("&Save"), this);
	_saveAct->setStatusTip(tr("Save General and Team"));

	const QIcon generateIcon = QIcon("./res/icons/gen-icon.png");
	_genAct = new QAction(generateIcon, tr("&Generate the planning"), this);
	_genAct->setStatusTip(tr("Generate the planning"));

	const QIcon synchronizeIcon = QIcon("./res/icons/sync-icon.png");
	_syncAct = new QAction(synchronizeIcon, tr("&Synchronize datas"), this);
	_syncAct->setStatusTip(tr("Synchronize datas"));

	_g_toolBar->addAction(_saveAct);
	_g_toolBar->addAction(_genAct);
	_g_toolBar->addAction(_syncAct);

	_g_toolBar->setMovable(false);
	_g_toolBar->setFloatable(false);
/***********/

	_g_defaultHoursEdit->setMinimum(0);

	connect(_g_allCheckbox, SIGNAL(stateChanged(int)), this, SLOT(generalAllCheckstate(int)));

	connect(_saveAct, SIGNAL(triggered()), this, SLOT(generalSaveDatas()));
	connect(_genAct, SIGNAL(triggered()), this, SLOT(generalCalculate()));
	connect(_syncAct, SIGNAL(triggered()), &_api, SLOT(getAll()));

	connect(&_api, SIGNAL(save_ended()), this, SLOT(reenableSave()));
	connect(&_api, SIGNAL(save_error()), this, SLOT(reenableSave()));

	connect(&_api, SIGNAL(compute_ended()), this, SLOT(reenableGen()));
	connect(&_api, SIGNAL(compute_error()), this, SLOT(reenableGen()));

	connect(&_api, SIGNAL(save_ended()), this, SLOT(computeIfNeeded()));
}

void MainWindow::initGeneralTab(QTabWidget* tabWidget, Globals initGlob){
	initGeneralTab(tabWidget);
	setValues(initGlob);
}

void MainWindow::setValues(Globals initGlob){
/* Init values with initGlob */
	_g_minTimeEdit->setTime(getQTimeFromFloat(initGlob.startMin));
	_g_maxTimeEdit->setTime(getQTimeFromFloat(initGlob.endMax));
	_g_defaultHoursEdit->setValue(initGlob.nbHours);

	if(initGlob.workedDays.size() == 7){
		_g_allCheckbox->setCheckState(Qt::Checked);
		return;
	}

	_g_allCheckbox->setCheckState(Qt::Unchecked);

	for(auto& checkbox : _g_daysCheckboxes){
		checkbox.second->setCheckState(Qt::Unchecked);
	}
	for(auto& day : initGlob.workedDays){
		_g_daysCheckboxes[day.c_str()]->setCheckState(Qt::Checked);
	}
/*****************************/
}

void MainWindow::deleteGeneralTab(QTabWidget*/* tabWidget*/){
	for(auto& dayCheckbox : _g_daysCheckboxes){
		mcd::deletePtr(dayCheckbox.second);
	}
	_g_daysCheckboxes.clear();
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

	for(auto& weekday : mcd::arguments["weekdays"]){
		_g_daysCheckboxes[weekday]->setCheckState(cState);
	}
}

void MainWindow::generalSaveDatas(){
	auto globals = translate();

	_saveAct->setEnabled(false);
	_api.save(globals, Planning());
}

void MainWindow::reenableSave(){
	_saveAct->setEnabled(true);
}

void MainWindow::reenableGen(){
	_genAct->setEnabled(true);
	_api.getAll();
}

void MainWindow::computeIfNeeded(){
	if(_genAct->isEnabled()){
		return;
	}
	_api.compute();
}

void MainWindow::generalCalculate(){
	auto globals = translate();

	_saveAct->setEnabled(false);
	_genAct->setEnabled(false);

	_api.save(globals, Planning());
}

Globals MainWindow::translate(){
	Globals out;

	auto min = _g_minTimeEdit->time();
	auto max = _g_maxTimeEdit->time();

	out.startMin = static_cast<float>(min.hour()) + static_cast<float>(min.minute()) / 60.0F + static_cast<float>(min.second()) / 3600.0F;
	out.endMax = static_cast<float>(max.hour()) + static_cast<float>(max.minute()) / 60.0F + static_cast<float>(max.second()) / 3600.0F;
	out.nbHours = static_cast<float>(_g_defaultHoursEdit->value());
	for(auto& weekday : mcd::arguments["weekdays"]){
		if(_g_daysCheckboxes[weekday]->checkState() != Qt::Unchecked){
			out.workedDays.push_back(weekday);
		}
	}

	return out;
}

QTime MainWindow::getQTimeFromFloat(float time){
	int t = static_cast<int>(time);
	int h = t;
	int m = static_cast<int>((time - static_cast<float>(h)) * 60);
	int s = static_cast<int>((time - static_cast<float>(h) - static_cast<float>(m)/60.0F) * 3600);

	return QTime(h, m, s);
}

void MainWindow::resetGeneralTab(QTabWidget* tabWidget){
	deleteGeneralTab(tabWidget);
	initGeneralTab(tabWidget);
}

void MainWindow::g_setAll(const Globals& gl, const std::vector<TeamMember>&, const Planning&){
	setValues(gl);
}
