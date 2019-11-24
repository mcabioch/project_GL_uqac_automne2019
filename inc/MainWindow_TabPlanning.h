#ifndef HEADER_MAINWINDOW_TAB_PLANNING
#define HEADER_MAINWINDOW_TAB_PLANNING

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
	void p_setAll(const Globals& gl, const std::vector<TeamMember>& tm, const Planning& pl);

signals:
	

protected:
	/* Getters of MainWindow */
		
	/* Setters of MainWindow */
		
	/* Statics of MainWindow */
		
	/* Friends of MainWindow */
		
	/* Others members of MainWindow */
		

private:
	void initPlanningTab(QTabWidget* tabWidget);
	void resetPlanningTab(QTabWidget* tabWidget);
	void deletePlanningTab(QTabWidget* tabWidget);

/* Atttributes of MainWindow */
public:
	/* Global */
		
	/* Local */
		

protected:
	/* Global */
		
	/* Local */
		Globals _p_globals;
		std::vector<TeamMember> _p_teamMembers;

private:
	/* Global */
		
	/* Local */
		QWidget* _planningTab;
		QVBoxLayout* _planningLay;

		Planning _planning;

#endif //HEADER_MAINWINDOW_TAB_PLANNING
