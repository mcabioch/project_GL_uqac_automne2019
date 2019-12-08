#ifndef HEADER_MAINWINDOW_TAB_GENERAL
#define HEADER_MAINWINDOW_TAB_GENERAL

/* Members of MainWindow */
public:
	/* Internal enums of MainWindow */
		
	/* Getters of MainWindow */
		
	/* Setters of MainWindow */
		
	/* Statics of MainWindow */
		
	/* Operators of MainWindow */
		
	/* Friends of MainWindow */
		
	/* Others members of MainWindow */
		

public slots:
	void generalAllCheckstate(int state);
	void generalSaveDatas();
	void generalCalculate();

	void reenableSave();
	void reenableGen();
	void computeIfNeeded();

	void g_setAll(const Globals& gl, const std::vector<TeamMember>& tm, const Planning& pl);

signals:
	

protected:
	/* Getters of MainWindow */
		
	/* Setters of MainWindow */
		
	/* Statics of MainWindow */
		
	/* Friends of MainWindow */
		
	/* Others members of MainWindow */
		

private:
	void initGeneralTab(QTabWidget* tabWidget);
	void initGeneralTab(QTabWidget* tabWidget, Globals initGlob);
	void resetGeneralTab(QTabWidget* tabWidget);
	void deleteGeneralTab(QTabWidget* tabWidget);
	void setValues(Globals initGlob);

	Globals translate();
	QTime getQTimeFromFloat(float time);

/* Atttributes of MainWindow */
public:
	/* Global */
		
	/* Local */
		

protected:
	/* Global */
		
	/* Local */
		

private:
	/* Global */
		
	/* Local */
		QWidget* _g_tab;
		QHBoxLayout* _g_lay;

		QCheckBox* _g_allCheckbox;
		std::map<std::string, QCheckBox*> _g_daysCheckboxes;
		QTimeEdit* _g_minTimeEdit;
		QTimeEdit* _g_maxTimeEdit;
		QDoubleSpinBox* _g_defaultHoursEdit;

		QToolBar* _g_toolBar;

		QAction* _saveAct;
		QAction* _genAct;
		QAction* _syncAct;

#endif //HEADER_MAINWINDOW_TAB_GENERAL
