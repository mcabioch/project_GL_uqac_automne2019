#include "Api.hpp"

Api::Api() :
	_managers(),
	_host(""),
	_token(""),
	_username("")
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

/* Slots */
void Api::auth_end(QNetworkReply* reply){
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		return;
	}

	/*auto headers = reply->rawHeaderPairs();

	mcd::logs(mcd::Logger::Debug, headers.size());
	for(const auto& header : headers){
		mcd::logs(mcd::Logger::Debug, header.first.toStdString(), ":", header.second.toStdString());
	}*/

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
