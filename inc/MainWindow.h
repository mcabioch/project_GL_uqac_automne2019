#ifndef HEADER_MAINWINDOW
#define HEADER_MAINWINDOW

#include "includes.h"

#include "Planning.h"
#include "AddMemberModal.h"

/*!
* \class	MainWindow
* \brief	The main window of the software
*/
class MainWindow : public QMainWindow {
	/* Usefull or required defines */
		Q_OBJECT
	/* Members of MainWindow */
	public:
		/* Constructors & Destructor of MainWindow */
			/*! \brief	The constructor of the class */
			MainWindow(Api& api, QWidget* parent = nullptr);
			virtual ~MainWindow();
		/* Others members of MainWindow */
			void initWindow();

	private:
		MainWindow(const MainWindow& other);
		MainWindow& operator=(const MainWindow& other);
		void init(const MainWindow* other = nullptr);
		void closeEvent(QCloseEvent* event);

	/* Atttributes of MainWindow */
	private:
		/* Local */
			QVBoxLayout* centerLayout;
			QWidget* center;

			QTabWidget* _tab;

	#include "MainWindow_TabGeneral.h"
	#include "MainWindow_TabTeam.h"
	#include "MainWindow_TabPlanning.h"

			Api& _api;
};

#endif //HEADER_MAINWINDOW
