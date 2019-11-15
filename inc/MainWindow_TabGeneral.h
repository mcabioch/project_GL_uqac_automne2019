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
		QVBoxLayout* _g_lay;

		QVBoxLayout* _g_daysChoice;
		QHBoxLayout* _g_checkAllLay;
		QCheckBox* _g_allCheckbox;
		QHBoxLayout* _g_checkDays;
		std::map<QString, QCheckBox*> _g_daysCheckboxes;

		QHBoxLayout* _g_minTimeLay;
		QTimeEdit* _g_minTimeEdit;
		QLabel* _g_minTimeLabel;

		QHBoxLayout* _g_maxTimeLay;
		QTimeEdit* _g_maxTimeEdit;
		QLabel* _g_maxTimeLabel;

		QHBoxLayout* _g_defaultHoursLay;
		QDoubleSpinBox* _g_defaultHoursEdit;
		QLabel* _g_defaultHoursLabel;

		QToolBar* _g_toolBar;

#endif //HEADER_MAINWINDOW_TAB_GENERAL
