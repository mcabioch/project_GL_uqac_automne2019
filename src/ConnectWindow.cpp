#include "ConnectWindow.h"

ConnectWindow::ConnectWindow(MainWindow& mainWind, QWidget* parent) :
	QMainWindow(parent),
	centerLayout(nullptr),
	center(nullptr),

	_mainWindow(mainWind),
	_signinWindow(nullptr),
	_username(nullptr),
	_password(nullptr),
	_connect(nullptr),
	_signin(nullptr)
{
	this->init();
}

ConnectWindow::ConnectWindow(const ConnectWindow& other) :
	QMainWindow(other.parentWidget()),
	centerLayout(nullptr),
	center(nullptr),

	_mainWindow(other._mainWindow),
	_signinWindow(nullptr),
	_username(nullptr),
	_password(nullptr),
	_connect(nullptr),
	_signin(nullptr)
{
	*this = other;
}

ConnectWindow& ConnectWindow::operator=(const ConnectWindow& other){
	this->init(&other);
	return *this;
}

ConnectWindow::~ConnectWindow(){
	mcd::logs(mcd::Logger::Debug, "ConnectWindow destroyed");
}

void ConnectWindow::init(const ConnectWindow*){
	/* Base */
		center = new QWidget;
		centerLayout = new QVBoxLayout;

		this->setWindowTitle("Login - Planning Generator");
		this->setCentralWidget(center);

		center->setLayout(centerLayout);
	/********/

	this->setStyleSheet(QString(cssReader("res/connect.css").c_str()));
	size_t w = 640;
	size_t h = 480;
	this->resize(static_cast<int>(w), static_cast<int>(h));
	this->move(static_cast<int>(getDesktopWidth()/2 - w/2), static_cast<int>(getDesktopHeight()/2 - h/2));

	_username = new QLineEdit();
	_password = new QLineEdit();
	_connect = new QPushButton("Connect");
	_signin = new QCommandLinkButton("Create account");

	_password->setEchoMode(QLineEdit::Password);
	_connect->setCursor(QCursor(Qt::PointingHandCursor));
	_signin->setCursor(QCursor(Qt::PointingHandCursor));

	auto hl_username = new QHBoxLayout();
	auto hl_password = new QHBoxLayout();
	auto hl_connect = new QHBoxLayout();
	auto hl_signin = new QHBoxLayout();

	hl_username->addItem(new QHSpacerItem());
	hl_username->addWidget(new QLabel("Username : "));
	hl_username->addWidget(_username);
	hl_username->addItem(new QHSpacerItem());

	hl_password->addItem(new QHSpacerItem());
	hl_password->addWidget(new QLabel("Password : "));
	hl_password->addWidget(_password);
	hl_password->addItem(new QHSpacerItem());

	hl_connect->addItem(new QHSpacerItem());
	hl_connect->addWidget(_connect);
	hl_connect->addItem(new QHSpacerItem());

	hl_signin->addItem(new QHSpacerItem());
	hl_signin->addWidget(_signin);
	hl_signin->addItem(new QHSpacerItem());

	centerLayout->addItem(new QVSpacerItem());
	centerLayout->addLayout(hl_username);
	centerLayout->addLayout(hl_password);
	centerLayout->addLayout(hl_connect);
	centerLayout->addLayout(hl_signin);
	centerLayout->addItem(new QVSpacerItem());

	connect(_connect, SIGNAL(released()), this, SLOT(connection()));
	connect(_signin, SIGNAL(released()), this, SLOT(signingin()));
	mcd::logs(mcd::Logger::Debug, "ConnectWindow created");
}

void ConnectWindow::showEvent(QShowEvent* event){
	size_t w = 640;
	size_t h = 480;
	this->resize(static_cast<int>(w), static_cast<int>(h));
	this->move(static_cast<int>(getDesktopWidth()/2 - w/2), static_cast<int>(getDesktopHeight()/2 - h/2));

	event->accept();
}

void ConnectWindow::connection(){
	if(_username->text() != "" && _password->text() != ""){
		mcd::logs(mcd::Logger::Debug, "Add API connection here");

		_mainWindow.initWindow();
		_mainWindow.show();
		this->hide();
	}
}

void ConnectWindow::signingin(){
	if(_signinWindow != nullptr){
		_signinWindow->show();
		this->hide();
	}
}
