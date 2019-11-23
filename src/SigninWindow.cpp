#include "SigninWindow.h"

SigninWindow::SigninWindow(QMainWindow* connectWindow, QWidget* parent) :
	QMainWindow(parent),
	centerLayout(nullptr),
	center(nullptr),

	_connectWindow(connectWindow),
	_username(nullptr),
	_password(nullptr),
	_passwordConf(nullptr),
	_signin(nullptr),
	_connect(nullptr)
{
	this->init();
}

SigninWindow::SigninWindow(const SigninWindow& other) :
	QMainWindow(other.parentWidget()),
	centerLayout(nullptr),
	center(nullptr),

	_connectWindow(other._connectWindow),
	_username(nullptr),
	_password(nullptr),
	_passwordConf(nullptr),
	_signin(nullptr),
	_connect(nullptr)
{
	*this = other;
}

SigninWindow& SigninWindow::operator=(const SigninWindow& other){
	this->init(&other);

	return *this;
}

SigninWindow::~SigninWindow(){
	mcd::logs(mcd::Logger::Debug, "SigninWindow destroyed");
}

void SigninWindow::init(const SigninWindow*){
	/* Base */
		center = new QWidget;
		centerLayout = new QVBoxLayout;

		this->setWindowTitle("Signin - Planning Generator");
		this->setCentralWidget(center);

		center->setLayout(centerLayout);
	/********/

	_username = new QLineEdit;
	_password = new QLineEdit;
	_passwordConf = new QLineEdit;
	_signin = new QPushButton("Create account");
	_connect = new QCommandLinkButton("Connection");

	_password->setEchoMode(QLineEdit::Password);
	_passwordConf->setEchoMode(QLineEdit::Password);
	_signin->setCursor(QCursor(Qt::PointingHandCursor));
	_connect->setCursor(QCursor(Qt::PointingHandCursor));

	auto hl_username = new QHBoxLayout;
	auto hl_password = new QHBoxLayout;
	auto hl_passwordConf = new QHBoxLayout;
	auto hl_signin = new QHBoxLayout;
	auto hl_connect = new QHBoxLayout;

	hl_username->addItem(new QHSpacerItem);
	hl_username->addWidget(new QLabel("Username :"));
	hl_username->addWidget(_username);
	hl_username->addItem(new QHSpacerItem);

	hl_password->addItem(new QHSpacerItem);
	hl_password->addWidget(new QLabel("Password :"));
	hl_password->addWidget(_password);
	hl_password->addItem(new QHSpacerItem);

	hl_passwordConf->addItem(new QHSpacerItem);
	hl_passwordConf->addWidget(new QLabel("Confirm password :"));
	hl_passwordConf->addWidget(_passwordConf);
	hl_passwordConf->addItem(new QHSpacerItem);

	hl_signin->addItem(new QHSpacerItem);
	hl_signin->addWidget(_signin);
	hl_signin->addItem(new QHSpacerItem);

	hl_connect->addItem(new QHSpacerItem);
	hl_connect->addWidget(_connect);
	hl_connect->addItem(new QHSpacerItem);

	centerLayout->addItem(new QVSpacerItem);
	centerLayout->addLayout(hl_username);
	centerLayout->addLayout(hl_password);
	centerLayout->addLayout(hl_passwordConf);
	centerLayout->addLayout(hl_signin);
	centerLayout->addLayout(hl_connect);
	centerLayout->addItem(new QVSpacerItem);

	connect(_signin, SIGNAL(released()), this, SLOT(signingin()));
	connect(_connect, SIGNAL(released()), this, SLOT(connection()));
	mcd::logs(mcd::Logger::Debug, "SigninWindow created");
}

void SigninWindow::showEvent(QShowEvent* event){
	size_t w = 640;
	size_t h = 480;
	this->resize(static_cast<int>(w), static_cast<int>(h));
	this->move(static_cast<int>(getDesktopWidth()/2 - w/2), static_cast<int>(getDesktopHeight()/2 - h/2));

	event->accept();
}

void SigninWindow::backConnect(){
	_connectWindow->show();
	this->hide();
}

void SigninWindow::signingin(){
	if(_connectWindow != nullptr){
		if(_password->text() == "" || _passwordConf->text() == "" || _username->text() == ""){
			return;
		}

		std::string border("border-style: inset; border-radius: 3px; ");

		if(_password->text() != _passwordConf->text()){
			_passwordConf->setText("");
			_passwordConf->setStyleSheet((border + "border: 1px solid red;").c_str());
			return;
		}

		std::string grey("170");
		_passwordConf->setStyleSheet((border + "border: 1px solid rgb(" + grey + ", " + grey + ", " + grey + ");").c_str());

		mcd::logs(mcd::Logger::Debug, "Add API connection here");
		this->backConnect();
	}
}

void SigninWindow::connection(){
	this->backConnect();
}
