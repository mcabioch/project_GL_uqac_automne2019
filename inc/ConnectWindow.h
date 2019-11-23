#ifndef HEADER_CONNECTWINDOW
#define HEADER_CONNECTWINDOW

#include "PAL.h"
#include "MCD.h"

#include "MainWindow.h"
#include "SigninWindow.h"

/*!
* \class	ConnectWindow
* \brief	The main window of the software
*/
class ConnectWindow : public QMainWindow {
	/* Usefull or required defines */
		Q_OBJECT
	/* Members of ConnectWindow */
	public:
		/* Internal enums of ConnectWindow */
			
		/* Constructors & Destructor of ConnectWindow */
			/*! \brief	The constructor of the class */
			ConnectWindow(MainWindow& mainWind, QWidget* parent = nullptr);
			virtual ~ConnectWindow();
		/* Getters of ConnectWindow */
			
		/* Setters of ConnectWindow */
			
		/* Statics of ConnectWindow */
			
		/* Operators of ConnectWindow */
			
		/* Friends of ConnectWindow */
			
		/* Others members of ConnectWindow */
			

	public slots:
		void connection();

	signals:
		

	protected:
		/* Getters of ConnectWindow */
			
		/* Setters of ConnectWindow */
			
		/* Statics of ConnectWindow */
			
		/* Friends of ConnectWindow */
			
		/* Others members of ConnectWindow */
			

	private:
		

	/* Atttributes of ConnectWindow */
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

			MainWindow& _mainWindow;

			QVSpacerItem* _vspacer;
			QHSpacerItem* _hspacer;

			std::map<std::string, QHBoxLayout*> _hlayouts;
			QLineEdit* _username;
			QLineEdit* _password;
			QPushButton* _connect;
			QLabel* _signin;
};

#endif //HEADER_CONNECTWINDOW
