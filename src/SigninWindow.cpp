#include "SigninWindow.h"

SigninWindow::SigninWindow(QWidget* parent) :
	QMainWindow(parent),
	centerLayout(nullptr),
	center(nullptr),

	_mainWindow(nullptr)
{
	/* Base */
		center = new QWidget;
		centerLayout = new QVBoxLayout;

		this->setWindowTitle("Planning Generator");
		this->setCentralWidget(center);

		center->setLayout(centerLayout);
	/********/
}

SigninWindow::~SigninWindow(){
	deletePtr(centerLayout);
	deletePtr(center);
}
