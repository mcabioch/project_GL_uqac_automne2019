#include "ConnectWindow.h"

#define ConnectWindow_INIT_LIST \
centerLayout(nullptr),\
center(nullptr),\
\
_signinWindow(nullptr),\
_username(nullptr),\
_password(nullptr),\
_connect(nullptr),\
m_signin(nullptr)\

ConnectWindow::ConnectWindow(MainWindow& mainWind, Api& api, QWidget* parent) :
	QMainWindow(parent),
	ConnectWindow_INIT_LIST,
	_mainWindow(mainWind),
	_api(api)
{
	this->init();
}

ConnectWindow::ConnectWindow(const ConnectWindow& other) :
	QMainWindow(other.parentWidget()),
	ConnectWindow_INIT_LIST,
	_mainWindow(other._mainWindow),
	_api(other._api)
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

	this->setStyleSheet(QString((cssReader("res/style.css")+cssReader("res/connect.css")).c_str()));
	size_t w = 720;
	size_t h = 405;
	this->resize(static_cast<int>(w), static_cast<int>(h));
	this->move(static_cast<int>(getDesktopWidth()/2 - w/2), static_cast<int>(getDesktopHeight()/2 - h/2));

	_username = new QLineEdit();
	_password = new QLineEdit();
	_connect = new QPushButton("Connect");
	m_signin = new QPushButton("Create account");

	_password->setEchoMode(QLineEdit::Password);
	_connect->setCursor(QCursor(Qt::PointingHandCursor));
	m_signin->setCursor(QCursor(Qt::PointingHandCursor));

	_connect->setProperty("class", "main-button");
	m_signin->setProperty("class", "second-button");

	_username->setPlaceholderText("Username");
	_password->setPlaceholderText("Password");

	auto hl_username = new QHBoxLayout();
	auto hl_password = new QHBoxLayout();
	auto hl_connect = new QHBoxLayout();
	auto hl_signin = new QHBoxLayout();

	hl_username->addItem(new QHSpacerItem());
	hl_username->addWidget(new IconedFormContainer(new QIcon("res/imgs/user_icon.png"), 18, _username));
	hl_username->addItem(new QHSpacerItem());

	hl_password->addItem(new QHSpacerItem());
	hl_password->addWidget(new IconedFormContainer(new QIcon("res/imgs/pass_icon.png"), 18, _password));
	hl_password->addItem(new QHSpacerItem());

	hl_connect->addItem(new QHSpacerItem());
	hl_connect->addWidget(_connect);
	hl_connect->addItem(new QHSpacerItem());

	hl_signin->addItem(new QHSpacerItem());
	hl_signin->addWidget(m_signin);
	hl_signin->addItem(new QHSpacerItem());

	centerLayout->addItem(new QVSpacerItem());
	centerLayout->addLayout(hl_username);
	centerLayout->addLayout(hl_password);
	centerLayout->addLayout(hl_connect);
	centerLayout->addLayout(hl_signin);
	centerLayout->addItem(new QVSpacerItem());

	connect(_connect, SIGNAL(released()), this, SLOT(connection()));
	connect(m_signin, SIGNAL(released()), this, SLOT(signingin()));

	connect(&_api, SIGNAL(auth_ended()), this, SLOT(reenableLinks()));
	connect(&_api, SIGNAL(auth_error()), this, SLOT(reenableLinks()));

	connect(&_api, SIGNAL(auth_ended()), &_api, SLOT(getAll()));
	connect(&_api, SIGNAL(getAll_ended()), this, SLOT(goThrough()));
	mcd::logs(mcd::Logger::Debug, "ConnectWindow created");
}

void ConnectWindow::testConnect(const std::string& user, const std::string& pass){
	_username->setText(user.c_str());
	_password->setText(pass.c_str());

	_connect->click();
}

void ConnectWindow::testRegister(){
	m_signin->click();
}

void ConnectWindow::showEvent(QShowEvent* event){
	size_t w = 720;
	size_t h = 405;
	this->resize(static_cast<int>(w), static_cast<int>(h));
	this->move(static_cast<int>(getDesktopWidth()/2 - w/2), static_cast<int>(getDesktopHeight()/2 - h/2));

	event->accept();
}

void ConnectWindow::connection(){
	if(_username->text() != "" && _password->text() != ""){
		_connect->setEnabled(false);
		m_signin->setEnabled(false);
		_api.auth(_username->text().toStdString(), _password->text().toStdString());
	}
}

void ConnectWindow::goThrough(){
	_mainWindow.initWindow();
	_mainWindow.show();
	this->hide();
}

void ConnectWindow::reenableLinks(){
	_connect->setEnabled(true);
	m_signin->setEnabled(true);
}

void ConnectWindow::signingin(){
	if(_signinWindow != nullptr){
		_signinWindow->show();
		this->hide();
	}
}
