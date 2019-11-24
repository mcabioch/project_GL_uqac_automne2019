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
		/* Internal enums of MainWindow */
			
		/* Constructors & Destructor of MainWindow */
			/*! \brief	The constructor of the class */
			MainWindow(Api& api, QWidget* parent = nullptr);
			virtual ~MainWindow();
		/* Getters of MainWindow */
			
		/* Setters of MainWindow */
			
		/* Statics of MainWindow */
			
		/* Operators of MainWindow */
			
		/* Friends of MainWindow */
			
		/* Others members of MainWindow */
			void initWindow();

	public slots:
		

	signals:
		

	protected:
		/* Getters of MainWindow */
			
		/* Setters of MainWindow */
			
		/* Statics of MainWindow */
			
		/* Friends of MainWindow */
			
		/* Others members of MainWindow */
			

	private:
		MainWindow(const MainWindow& other);
		MainWindow& operator=(const MainWindow& other);
		void init(const MainWindow* other = nullptr);

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

			Api& _api;
};

#endif //HEADER_MAINWINDOW
