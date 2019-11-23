#ifndef HEADER_SIGNINWINDOW
#define HEADER_SIGNINWINDOW

#include "PAL.h"
#include "MCD.h"

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
			SigninWindow(QMainWindow*& connectWindow, QWidget* parent = nullptr);
			virtual ~SigninWindow();
		/* Getters of SigninWindow */
			
		/* Setters of SigninWindow */
			
		/* Statics of SigninWindow */
			
		/* Operators of SigninWindow */
			
		/* Friends of SigninWindow */
			
		/* Others members of SigninWindow */
			

	public slots:
		

	signals:
		

	protected:
		/* Getters of SigninWindow */
			
		/* Setters of SigninWindow */
			
		/* Statics of SigninWindow */
			
		/* Friends of SigninWindow */
			
		/* Others members of SigninWindow */
			

	private:
		

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

			QMainWindow*& _connectWindow;
};

#endif //HEADER_SIGNINWINDOW
