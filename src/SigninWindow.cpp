#include "SigninWindow.h"

SigninWindow::SigninWindow(QMainWindow*& connectWindow, QWidget* parent) :
	QMainWindow(parent),
	centerLayout(nullptr),
	center(nullptr),

	_connectWindow(connectWindow)
{
	/* Base */
		center = new QWidget;
		centerLayout = new QVBoxLayout;

		this->setWindowTitle("Signin - Planning Generator");
		this->setCentralWidget(center);

		center->setLayout(centerLayout);
	/********/
}

SigninWindow::~SigninWindow(){
	deletePtr(centerLayout);
	deletePtr(center);
}
