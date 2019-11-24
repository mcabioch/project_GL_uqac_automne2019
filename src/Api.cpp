#include "Api.hpp"

Api::Api() :
	_managers(),
	_host(""),
	_token(""),
	_username(""),
	_teamName("")
{
	mcd::logs(mcd::Logger::Debug, "Api created");

	_managers["auth"] = nullptr;
}

Api::~Api(){
	mcd::logs(mcd::Logger::Debug, "Api destroyed");
}

bool Api::connection(const std::string& host){
	_host = host;

	_managers["auth"] = new QNetworkAccessManager;
	_managers["auth"]->connectToHost(_host.c_str(), 8080);

	return true;
}

void Api::auth(const std::string& user, const std::string& pass){
	std::stringstream txt;

	txt << user << ":" << pass;
	auto encoded = base64_encode(txt.str());

	std::string value("Basic ");
	value += encoded;

	std::string str_url = std::string("http://")+_host+":8080/auth";
	mcd::logs(mcd::Logger::Debug, "url:", str_url);

	QNetworkRequest req(QUrl(str_url.c_str()));
	req.setRawHeader(QByteArray("Authorization"), QByteArray(value.c_str()));

	if(_managers["auth"] == nullptr){
		_managers["auth"] = new QNetworkAccessManager;
		_managers["auth"]->connectToHost(_host.c_str(), 8080);
	}

	connect(_managers["auth"], SIGNAL(finished(QNetworkReply*)), this, SLOT(auth_end(QNetworkReply*)));

	_username = user;
	_managers["auth"]->get(req);

	return;
}

void Api::signin(const AuthUser& user, const AuthMember& member, const std::string& teamName){
	if(user.username == "" || member.firstname == "" || teamName == ""){}
	mcd::logs(mcd::Logger::Warn, "Signin for register");
}

void Api::signin(const AuthUser& user, const AuthMember& member){
	if(user.username == "" || member.firstname == ""){}
	mcd::logs(mcd::Logger::Warn, "Signin from modal");
}

void Api::save(const Globals& team, const Planning& planning){
	if(team.startMin && planning.get()){}
	mcd::logs(mcd::Logger::Warn, "Save all");
}

void Api::getAll(){
	mcd::logs(mcd::Logger::Warn, "Get all");
}

void Api::compute(){
	mcd::logs(mcd::Logger::Warn, "Compute");
}

/* Slots */
void Api::auth_end(QNetworkReply* reply){
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		emit auth_error();
		return;
	}

	auto headers = reply->rawHeaderPairs();

	mcd::logs(mcd::Logger::Debug, headers.size());
	for(const auto& header : headers){
		mcd::logs(mcd::Logger::Debug, header.first.toStdString(), ":", header.second.toStdString());
	}

	auto body = reply->readAll().toStdString();

	if(body != ""){
		_token = body;
		emit auth_ended();
	}
	if(_token == ""){
		_username = "";
		emit auth_error();
	}
}

/* Protected */
std::string Api::base64_encode(const std::string& str){
	QByteArray ba;
	ba.append(QString(str.c_str()));
	return ba.toBase64().toStdString();
}
