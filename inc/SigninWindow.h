#ifndef HEADER_SIGNINWINDOW
#define HEADER_SIGNINWINDOW

#include "RegisterWidget.h"

/*!
* \class	SigninWindow
* \brief	The main window of the software
*/
class SigninWindow : public QMainWindow {
	/* Usefull or required defines */
		Q_OBJECT
	/* Members of SigninWindow */
	public:
		/* Internal enums of SigninWindow */
			
		/* Constructors & Destructor of SigninWindow */
			/*! \brief	The constructor of the class */
			SigninWindow(QMainWindow* connectWindow, Api& api, QWidget* parent = nullptr);
			virtual ~SigninWindow();

			
		/* Getters of SigninWindow */
			
		/* Setters of SigninWindow */
			
		/* Statics of SigninWindow */
			
		/* Operators of SigninWindow */
			
		/* Friends of SigninWindow */
			
		/* Others members of SigninWindow */
			

	public slots:
		void signingin();
		void connection();

	signals:
		

	protected:
		/* Getters of SigninWindow */
			
		/* Setters of SigninWindow */
			
		/* Statics of SigninWindow */
			
		/* Friends of SigninWindow */
			
		/* Others members of SigninWindow */
			void showEvent(QShowEvent* event);

	private:
		SigninWindow(const SigninWindow& other);
		SigninWindow& operator=(const SigninWindow& other);
		void init(const SigninWindow* other = nullptr);

		void backConnect();

	/* Atttributes of SigninWindow */
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

			RegisterWidget* _registerer;
			QLineEdit* _teamName;
			QPushButton* _signin;
			QCommandLinkButton* _connect;

			QMainWindow* _connectWindow;
			Api& _api;
};

#endif //HEADER_SIGNINWINDOW
