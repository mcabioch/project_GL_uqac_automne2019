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

	QNetworkRequest req(QUrl(createUrl(":8080/auth").c_str()));
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
	register_end(nullptr);
}

void Api::signin(const AuthUser& user, const AuthMember& member){
	if(user.username == "" || member.firstname == ""){}
	mcd::logs(mcd::Logger::Warn, "Signin from modal");
	signin_end(nullptr);
}

void Api::save(const Globals& team, const Planning& planning){
	if(team.startMin && planning.get()){}
	mcd::logs(mcd::Logger::Warn, "Save all");
	save_end(nullptr);
}

void Api::saveMembers(const std::vector<TeamMember>& team){
	if(team.size()){}
	mcd::logs(mcd::Logger::Warn, "Save members");
	saveMembers_end(nullptr);
}

void Api::deleteMember(const std::string& id){
	if(id.size()){}
	mcd::logs(mcd::Logger::Warn, "Delete member", id);
}

void Api::getAll(){
	mcd::logs(mcd::Logger::Warn, "Get all");
	getAll_end(nullptr);
}

void Api::compute(){
	mcd::logs(mcd::Logger::Warn, "Compute");
	compute_end(nullptr);
}

/* Slots */
void Api::auth_end(QNetworkReply* reply){
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		emit auth_error();
		return;
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

void Api::register_end(QNetworkReply* reply){
	emit signin_error();
	return;
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		emit signin_error();
		return;
	}

	auto body = reply->readAll().toStdString();

	if(body != ""){
		
		emit signin_ended();
	}
}

void Api::signin_end(QNetworkReply* reply){
	emit signin_ended("0");
	return;
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		emit signin_error("0");
		return;
	}

	auto body = reply->readAll().toStdString();

	if(body != ""){
		
		emit signin_ended("0");
	}
}

void Api::save_end(QNetworkReply* reply){
	emit save_ended();
	return;
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		emit save_error();
		return;
	}

	auto body = reply->readAll().toStdString();

	if(body != ""){
		
		emit save_ended();
	}
}

void Api::saveMembers_end(QNetworkReply* reply){
	emit saveMembers_ended();
	return;
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		emit saveMembers_error();
		return;
	}

	auto body = reply->readAll().toStdString();

	if(body != ""){
		
		emit saveMembers_ended();
	}
}

void Api::getAll_end(QNetworkReply* reply){
	emit getAll_ended(Globals(8.0F, 19.5F, 35.0F, {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}),
							std::vector<TeamMember>({TeamMember("1", 0, "Robert", "Patt", {"Tuesday", "Friday"})}),
							Planning());
	return;
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		emit getAll_error();
		return;
	}

	auto body = reply->readAll().toStdString();

	if(body != ""){
		
		emit getAll_ended(Globals(),
							std::vector<TeamMember>(),
							Planning());
	}
}

void Api::compute_end(QNetworkReply* reply){
	emit compute_ended();
	return;
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		emit compute_error();
		return;
	}

	auto body = reply->readAll().toStdString();

	if(body != ""){
		
		emit compute_ended();
	}
}

/* Protected */
std::string Api::base64_encode(const std::string& str){
	QByteArray ba;
	ba.append(QString(str.c_str()));
	return ba.toBase64().toStdString();
}

/* Private */
std::string Api::createUrl(const std::string& str){
	std::string str_url = _host+str;
	mcd::logs(mcd::Logger::Debug, "url:", str_url);

	return str_url;
}
