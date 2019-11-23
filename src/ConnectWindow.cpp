#include "ConnectWindow.h"

ConnectWindow::ConnectWindow(MainWindow& mainWind, QWidget* parent) :
	QMainWindow(parent),
	centerLayout(nullptr),
	center(nullptr),

	_mainWindow(mainWind),
	_vspacer(nullptr),
	_hspacer(nullptr),
	_hlayouts(),
	_username(nullptr),
	_password(nullptr),
	_connect(nullptr),
	_signin(nullptr)
{
	/* Base */
		center = new QWidget;
		centerLayout = new QVBoxLayout;

		size_t w = 640;
		size_t h = 480;
		this->setWindowTitle("Login - Planning Generator");
		this->resize(w, h);
		this->move(getDesktopWidth()/2 - w/2, getDesktopHeight()/2 - h/2);
		this->setCentralWidget(center);

		center->setLayout(centerLayout);
	/********/

	this->setStyleSheet(QString(cssReader("res/connect.css").c_str()));

	_vspacer = new QVSpacerItem();
	_hspacer = new QHSpacerItem();

	_username = new QLineEdit();
	_password = new QLineEdit();
	_connect = new QPushButton("Connect");
	_signin = new QLabel("Create account");

	_password->setEchoMode(QLineEdit::Password);
	_connect->setCursor(QCursor(Qt::PointingHandCursor));
	_signin->setCursor(QCursor(Qt::PointingHandCursor));

	_hlayouts["username"] = new QHBoxLayout();
	_hlayouts["password"] = new QHBoxLayout();
	_hlayouts["connect"] = new QHBoxLayout();
	_hlayouts["signin"] = new QHBoxLayout();

	_hlayouts["username"]->addItem(_hspacer);
	_hlayouts["username"]->addWidget(new QLabel("Username : "));
	_hlayouts["username"]->addWidget(_username);
	_hlayouts["username"]->addItem(_hspacer);

	_hlayouts["password"]->addItem(_hspacer);
	_hlayouts["password"]->addWidget(new QLabel("Password : "));
	_hlayouts["password"]->addWidget(_password);
	_hlayouts["password"]->addItem(_hspacer);

	_hlayouts["connect"]->addItem(_hspacer);
	_hlayouts["connect"]->addWidget(_connect);
	_hlayouts["connect"]->addItem(_hspacer);

	_hlayouts["signin"]->addItem(_hspacer);
	_hlayouts["signin"]->addWidget(_signin);
	_hlayouts["signin"]->addItem(_hspacer);

	centerLayout->addItem(_vspacer);
	centerLayout->addLayout(_hlayouts["username"]);
	centerLayout->addLayout(_hlayouts["password"]);
	centerLayout->addLayout(_hlayouts["connect"]);
	centerLayout->addLayout(_hlayouts["signin"]);
	centerLayout->addItem(_vspacer);

	connect(_connect, SIGNAL(released()), this, SLOT(connection()));
}

ConnectWindow::~ConnectWindow(){
	for(auto& item : _hlayouts){
		clearLayout(item.second);
	}

	clearLayout(centerLayout);

	deletePtr(_hspacer);
	deletePtr(_username);
	deletePtr(_password);
	deletePtr(_connect);
	deletePtr(_signin);

	for(auto& item : _hlayouts){
		deletePtr(item.second);
	}

	deletePtr(_vspacer);

	deletePtr(centerLayout);
	deletePtr(center);
}

void ConnectWindow::connection(){
	if(_username->text() != "" && _password->text() != ""){
		mcd::logs(mcd::Logger::Debug, "Add API connection here");

		_mainWindow.init();
		_mainWindow.show();
		this->hide();
	}
}
