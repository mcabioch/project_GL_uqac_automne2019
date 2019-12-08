#include "SigninWindow.h"

#define SigninWindow_INIT_LIST \
centerLayout(nullptr),\
center(nullptr),\
\
_registerer(nullptr),\
_teamName(nullptr),\
_signin(nullptr),\
_connect(nullptr)

SigninWindow::SigninWindow(QMainWindow* connectWindow, Api& api, QWidget* parent) :
	QMainWindow(parent),
	SigninWindow_INIT_LIST,
	_connectWindow(connectWindow),
	_api(api)
{
	this->init();
}

SigninWindow::SigninWindow(const SigninWindow& other) :
	QMainWindow(other.parentWidget()),
	SigninWindow_INIT_LIST,
	_connectWindow(other._connectWindow),
	_api(other._api)
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
	this->setStyleSheet(QString((cssReader("res/style.css")+cssReader("res/signin.css")).c_str()));

	_registerer = new RegisterWidget();
	_teamName = new QLineEdit();
	_signin = new QPushButton("Create account");
	_connect = new QPushButton("Connection");

	_signin->setProperty("class", "main-button");
	_connect->setProperty("class", "second-button");

	_teamName->setPlaceholderText("Team Name");
	_signin->setCursor(QCursor(Qt::PointingHandCursor));
	_connect->setCursor(QCursor(Qt::PointingHandCursor));

	auto hl_signin = new QHBoxLayout;
	auto hl_connect = new QHBoxLayout;
	auto hl_form = new QHBoxLayout;
	auto vl_formLeft = new QVBoxLayout;
	auto vl_formRight = new QVBoxLayout;

	hl_signin->addItem(new QHSpacerItem);
	hl_signin->addWidget(_signin);
	hl_signin->addItem(new QHSpacerItem);

	hl_connect->addItem(new QHSpacerItem);
	hl_connect->addWidget(_connect);
	hl_connect->addItem(new QHSpacerItem);

	int icon_size = 18;
	vl_formLeft->addWidget(new IconedFormContainer(new QIcon("res/imgs/user_icon.png"), icon_size, _registerer->_firstName));
	vl_formLeft->addWidget(new IconedFormContainer(new QIcon("res/imgs/user_icon.png"), icon_size, _registerer->_lastName));
	vl_formLeft->addWidget(new IconedFormContainer(new QIcon("res/imgs/user_icon.png"), icon_size, _registerer->_username));
	vl_formLeft->addWidget(new IconedFormContainer(new QIcon("res/imgs/pass_icon.png"), icon_size, _registerer->_password));
	vl_formLeft->addWidget(new IconedFormContainer(new QIcon("res/imgs/pass_icon.png"), icon_size, _registerer->_passwordConf));
	vl_formLeft->addWidget(new IconedFormContainer(new QIcon("res/imgs/users_icon.png"), icon_size+4, _teamName));

	vl_formRight->addWidget(new IconedFormContainer(new QIcon("res/imgs/clock_icon.png"), icon_size, _registerer->_hoursPerWeek, "Hours/week "));
	vl_formRight->addWidget(new IconedFormContainer(new QIcon("res/imgs/dayoff_icon.png"), icon_size, _registerer->_checkAll, "Days off "));
	for(auto& day : mcd::arguments["weekdays"]){
		vl_formRight->addWidget(_registerer->_t_daysCheckboxes[day]);
	}

	hl_form->addItem(new QHSpacerItem);
	hl_form->addLayout(vl_formLeft);
	hl_form->addLayout(vl_formRight);
	hl_form->addItem(new QHSpacerItem);

	centerLayout->addItem(new QVSpacerItem);
	centerLayout->addLayout(hl_form);
	centerLayout->addLayout(hl_signin);
	centerLayout->addLayout(hl_connect);
	centerLayout->addItem(new QVSpacerItem);

	connect(_signin, SIGNAL(released()), this, SLOT(signingin()));
	connect(_connect, SIGNAL(released()), this, SLOT(connection()));

	connect(&_api, SIGNAL(signin_ended()), this, SLOT(reenableLinks()));
	connect(&_api, SIGNAL(signin_error()), this, SLOT(reenableLinks()));

	connect(&_api, SIGNAL(signin_ended()), this, SLOT(goThrough()));
	mcd::logs(mcd::Logger::Debug, "SigninWindow created");
}

void SigninWindow::showEvent(QShowEvent* event){
	size_t w = 720;
	size_t h = 405;
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
		if(_registerer->_password->text() == "" || _registerer->_passwordConf->text() == "" || _registerer->_username->text() == ""
		|| _registerer->_firstName->text() == "" || _registerer->_lastName->text() == "" || _teamName->text() == ""){
			return;
		}

		std::string border("border-style: inset; border-radius: 3px; ");

		if(_registerer->_password->text() != _registerer->_passwordConf->text()){
			_registerer->_passwordConf->setText("");
			_registerer->_passwordConf->setStyleSheet((border + "border: 1px solid red;").c_str());
			return;
		}

		std::string grey("170");
		_registerer->_passwordConf->setStyleSheet((border + "border: 1px solid rgb(" + grey + ", " + grey + ", " + grey + ");").c_str());

		_api.signin(AuthUser(_registerer->_username->text().toStdString(), _registerer->_password->text().toStdString()),
					AuthMember(_registerer->_firstName->text().toStdString(), _registerer->_lastName->text().toStdString(),
								_registerer->getDaysOff(), _registerer->_hoursPerWeek->value()),
					_teamName->text().toStdString());

		_signin->setEnabled(false);
		_connect->setEnabled(false);
	}
}

void SigninWindow::goThrough(){
	mcd::logs(mcd::Logger::Warn, "Add API connection here");
	this->backConnect();
}

void SigninWindow::reenableLinks(){
	_signin->setEnabled(true);
	_connect->setEnabled(true);
}

void SigninWindow::connection(){
	this->backConnect();
}
