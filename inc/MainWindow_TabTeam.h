#ifndef HEADER_MAINWINDOW_TAB_TEAM
#define HEADER_MAINWINDOW_TAB_TEAM

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
	void addMember();
	void editMember(QTableWidgetItem *item);
	void deleteMember();
	void updateSelectedMember(int row, int);

	void t_setAll(const Globals& gl, const std::vector<TeamMember>& tm, const Planning& pl);

signals:
	

protected:
	/* Getters of MainWindow */
		
	/* Setters of MainWindow */
		
	/* Statics of MainWindow */
		
	/* Friends of MainWindow */
		
	/* Others members of MainWindow */

private:
	void initTeamTab(QTabWidget* tabWidget);
	void resetTeamTab(QTabWidget* tabWidget);
	void deleteTeamTab(QTabWidget* tabWidget);
	void initTeamTable();
	
/* Atttributes of MainWindow */
public:
	/* Global */
		
	/* Local */
	friend bool operator==(const TeamMember& a, const int& b);

protected:
	/* Global */
		
	/* Local */
		

private:
	/* Global */
		
	/* Local */
		QMainWindow* _teamTab;
		QWidget* _teamCenter;
		QVBoxLayout* _teamLay;
		QToolBar* _teamToolBar;
		QTableWidget *_teamTable;

		int selectedMember;

		std::vector<TeamMember> teamMembers;
		std::vector<TeamMember> selectedTeamMembers;

#endif //HEADER_MAINWINDOW_TAB_TEAM
