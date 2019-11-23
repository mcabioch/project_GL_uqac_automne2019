#ifndef HEADER_MAINWINDOW
#define HEADER_MAINWINDOW

#define DEBUG

#include "PAL.h"
#include "MCD.h"

#include "C++/C++.hpp"

/*!
* \class	MainWindow
* \brief	The main window of the software
*/
class MainWindow : public QMainWindow {
	/* Usefull or required defines */
		Q_OBJECT
	/* Members of MainWindow */
	public:
		/* Internal enums of MainWindow */
			
		/* Constructors & Destructor of MainWindow */
			/*! \brief	The constructor of the class */
			MainWindow(QWidget* parent = nullptr);
			virtual ~MainWindow();
		/* Getters of MainWindow */
			
		/* Setters of MainWindow */
			
		/* Statics of MainWindow */
			
		/* Operators of MainWindow */
			
		/* Friends of MainWindow */
			
		/* Others members of MainWindow */
			void init();

	public slots:
		

	signals:
		

	protected:
		/* Getters of MainWindow */
			
		/* Setters of MainWindow */
			
		/* Statics of MainWindow */
			
		/* Friends of MainWindow */
			
		/* Others members of MainWindow */
			

	private:
		

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
			QVBoxLayout* centerLayout;
			QWidget* center;

			QTabWidget* _tab;

			std::vector<QString> _weekdays;

	#include "MainWindow_TabGeneral.h"
	#include "MainWindow_TabTeam.h"
	#include "MainWindow_TabPlanning.h"
};

#endif //HEADER_MAINWINDOW
