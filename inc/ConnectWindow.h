#ifndef HEADER_CONNECTWINDOW
#define HEADER_CONNECTWINDOW

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
			ConnectWindow(MainWindow& mainWind, Api& api, QWidget* parent = nullptr);
			virtual ~ConnectWindow();
		/* Getters of ConnectWindow */
			
		/* Setters of ConnectWindow */
			
		/* Statics of ConnectWindow */
			
		/* Operators of ConnectWindow */
			
		/* Friends of ConnectWindow */
			
		/* Others members of ConnectWindow */
			inline void link(SigninWindow* wind){
				_signinWindow = wind;
			}
			void testConnect(const std::string& user, const std::string& pass);
			void testRegister();

	public slots:
		void connection();
		void signingin();
		void goThrough();
		void reenableLinks();

	signals:
		

	protected:
		/* Getters of ConnectWindow */
			
		/* Setters of ConnectWindow */
			
		/* Statics of ConnectWindow */
			
		/* Friends of ConnectWindow */
			
		/* Others members of ConnectWindow */
			void showEvent(QShowEvent* event);

	private:
		ConnectWindow(const ConnectWindow& other);
		ConnectWindow& operator=(const ConnectWindow& other);
		void init(const ConnectWindow* other = nullptr);

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

			SigninWindow* _signinWindow;

			QLineEdit* _username;
			QLineEdit* _password;
			QPushButton* _connect;
			QCommandLinkButton* _signin;

			MainWindow& _mainWindow;
			Api& _api;
};

#endif //HEADER_CONNECTWINDOW
