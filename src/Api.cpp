#include "Api.hpp"

Api::Api() :
	_managers(),
	_urls(),
	_host(""),
	_token(""),
	_userid(""),
	_username(""),
	_teamid(""),
	_teammemberid(""),
	_chef(false),
	_firstGet(true)
{
	mcd::logs(mcd::Logger::Debug, "Api created");

	_managers["auth"] = nullptr;
	_managers["getAll"] = nullptr;

	_managers["register user"] = nullptr;
	_managers["register team"] = nullptr;
	_managers["register teammember"] = nullptr;
}

Api::~Api(){
	mcd::logs(mcd::Logger::Debug, "Api destroyed");
}

bool Api::connection(const std::string& host){
	_host = host;

	_managers["auth"] = new QNetworkAccessManager;
	_managers["auth"]->connectToHost(_host.c_str(), 4000);

	return true;
}

void Api::auth(const std::string& user, const std::string& pass){
	std::stringstream txt;
	txt << user << ":" << pass;

	auto req = createRequest(":4000/graphql?query={auth(header:\"" + base64_encode(txt.str()) + "\"){userId, token, teamId}}",
							 "auth");

	connect(_managers["auth"], SIGNAL(finished(QNetworkReply*)), this, SLOT(auth_end(QNetworkReply*)));

	_username = user;
	_managers["auth"]->get(req);

	return;
}

void Api::signin(const AuthUser& user, const AuthMember& member, const std::string& teamName){
	if(user.username == "" || member.firstname == "" || teamName == ""){}

	auto req = createRequest(":4000/graphql?query={register(username:\"" + user.username + "\", pass:\"" + BCrypt::generateHash(user.password) + "\", name:\"" + member.firstname + "\", surname:\"" + member.lastname + "\"){id}}",
							 "register user");

	connect(_managers["register user"], SIGNAL(finished(QNetworkReply*)), this, SLOT(register_user_end(QNetworkReply*)));

	/* team request */
	createRequest(":4000/graphql?query={createTeam(defaultHeures: 0, nonTravail: \"Monday Tuesday Wednesday Thursday Friday Saturday\", creneauDebut: \"00:00\", creneauFin: \"00:00\", chefId: \"??userId??\"){id}}",
				  "register team");
	/* teammember request */
	createRequest(":4000/graphql?query={createTeamMember(teamId: \"??teamId??\", userId: \"??userId??\", jourDeRepos: \"" + member.daysOff + "\", nbHeures: " + mcd::tos(member.nbHours) + "){id}}",
				  "register teammember");

	_managers["register user"]->get(req);
}

void Api::signin(const AuthUser& user, const AuthMember& member){
	if(user.username == "" || member.firstname == ""){}

	auto req = createRequest(":4000/graphql?query={register(username:\"" + user.username + "\", pass:\"" + BCrypt::generateHash(user.password) + "\", name:\"" + member.firstname + "\", surname:\"" + member.lastname + "\"){id}}",
							 "signin user");

	connect(_managers["signin user"], SIGNAL(finished(QNetworkReply*)), this, SLOT(signin_user_end(QNetworkReply*)));

	/* teammember request */
	createRequest(":4000/graphql?query={createTeamMember(teamId: \"" + _teamid + "\", userId: \"??userId??\", jourDeRepos: \"" + member.daysOff + "\", nbHeures: " + mcd::tos(member.nbHours) + "){id}}",
				  "signin teammember");

	_managers["signin user"]->get(req);
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
	auto req = createRequest(":4000/graphql?query={team(id:\"" + _teamid + "\"){chef{user{id}},defaultHeures,nonTravail,creneau{debut,fin},teamMembers{user{id,name,surname},nbHeures,jourDeRepos}}}",
							 "getAll");

	connect(_managers["getAll"], SIGNAL(finished(QNetworkReply*)), this, SLOT(getAll_end(QNetworkReply*)));

	_managers["getAll"]->get(req);
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
		mcd::logs(mcd::Logger::Debug, body);
		auto json = jsonParse(body);

		if(!json.contains("data") || json.contains("errors") || json.empty()){
			printJsonError(json.take("errors").toArray()[0].toObject());
			emit auth_error();
			return;
		}

		auto auth_json = json.take("data").toObject().take("auth").toObject();
		_token = auth_json.take("token").toString().toStdString();
		_userid = auth_json.take("userId").toString().toStdString();
		_teamid = auth_json.take("teamId").toString().toStdString();

		emit auth_ended();
		return;
	}
	if(_token == ""){
		_username = "";
		emit auth_error();
	}
}

void Api::register_user_end(QNetworkReply* reply){
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		emit signin_error();
		return;
	}

	auto body = reply->readAll().toStdString();

	if(body != ""){
		mcd::logs(mcd::Logger::Debug, body);
		auto json = jsonParse(body);

		if(!json.contains("data") || json.contains("errors") || json.empty()){
			printJsonError(json.take("errors").toArray()[0].toObject());
			emit signin_error();
			return;
		}

		auto register_json = json.take("data").toObject().take("register").toObject();
		_userid = register_json.take("id").toString().toStdString();

		/* Launch next request */
			auto req = createRequest(mcd::implode(mcd::explode(_urls["register team"], "??userId??"), _userid),
									 "register team");

			connect(_managers["register team"], SIGNAL(finished(QNetworkReply*)), this, SLOT(register_team_end(QNetworkReply*)));

			_urls["register teammember"] = mcd::implode(mcd::explode(_urls["register teammember"], "??userId??"), _userid);
			_managers["register team"]->get(req);
		/***********************/
	}
}

void Api::register_team_end(QNetworkReply* reply){
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		emit signin_error();
		return;
	}

	auto body = reply->readAll().toStdString();

	if(body != ""){
		mcd::logs(mcd::Logger::Debug, body);
		auto json = jsonParse(body);

		if(!json.contains("data") || json.contains("errors") || json.empty()){
			printJsonError(json.take("errors").toArray()[0].toObject());
			emit signin_error();
			return;
		}

		auto register_json = json.take("data").toObject().take("createTeam").toObject();
		_teamid = register_json.take("id").toString().toStdString();

		/* Launch next request */
			auto req = createRequest(mcd::implode(mcd::explode(_urls["register teammember"], "??teamId??"), _teamid),
									 "register teammember");

			connect(_managers["register teammember"], SIGNAL(finished(QNetworkReply*)), this, SLOT(register_teammember_end(QNetworkReply*)));

			_managers["register teammember"]->get(req);
		/***********************/
	}
}

void Api::register_teammember_end(QNetworkReply* reply){
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		emit signin_error();
		return;
	}

	auto body = reply->readAll().toStdString();

	if(body != ""){
		mcd::logs(mcd::Logger::Debug, body);
		auto json = jsonParse(body);

		if(!json.contains("data") || json.contains("errors") || json.empty()){
			printJsonError(json.take("errors").toArray()[0].toObject());
			emit signin_error();
			return;
		}

		auto register_json = json.take("data").toObject().take("createTeamMember").toObject();
		_teammemberid = register_json.take("id").toString().toStdString();
		register_end(reply);
	}
}

void Api::register_end(QNetworkReply*){
	emit signin_ended();
}

void Api::signin_user_end(QNetworkReply* reply){
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		emit signin_error("0");
		return;
	}

	auto body = reply->readAll().toStdString();

	if(body != ""){
		mcd::logs(mcd::Logger::Debug, body);
		auto json = jsonParse(body);

		if(!json.contains("data") || json.contains("errors") || json.empty()){
			printJsonError(json.take("errors").toArray()[0].toObject());
			emit signin_error("0");
			return;
		}

		auto register_json = json.take("data").toObject().take("register").toObject();
		auto userid = register_json.take("id").toString().toStdString();

		/* Launch next request */
			auto req = createRequest(mcd::implode(mcd::explode(_urls["signin teammember"], "??userId??"), userid),
									 "signin teammember");

			connect(_managers["signin teammember"], SIGNAL(finished(QNetworkReply*)), this, SLOT(signin_teammember_end(QNetworkReply*)));

			_managers["signin teammember"]->get(req);
		/***********************/
	}
}

void Api::signin_teammember_end(QNetworkReply* reply){
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		emit signin_error();
		return;
	}

	auto body = reply->readAll().toStdString();

	if(body != ""){
		mcd::logs(mcd::Logger::Debug, body);
		auto json = jsonParse(body);

		if(!json.contains("data") || json.contains("errors") || json.empty()){
			printJsonError(json.take("errors").toArray()[0].toObject());
			emit signin_error("0");
			return;
		}

		auto register_json = json.take("data").toObject().take("createTeamMember").toObject();
		//auto teammemberid = register_json.take("id").toString().toStdString();

		std::string start_str = "userId: \"";
		auto start = _urls["signin teammember"].find(start_str);
		auto end = _urls["signin teammember"].find("\", jourDeRepos:");

		emit signin_ended(_urls["signin teammember"].substr(start+start_str.size(), end-start-start_str.size()));
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
	if(reply == nullptr || reply->error() != QNetworkReply::NoError){
		emit getAll_error();
		return;
	}

	auto body = reply->readAll().toStdString();

	if(body != ""){
		auto json = jsonParse(body);
		mcd::logs(mcd::Logger::Debug, body);

		if(!json.contains("data") || json.contains("errors") || json.empty()){
			printJsonError(json.take("errors").toArray()[0].toObject());
			emit getAll_error();
			return;
		}

		auto team_json = json.take("data").toObject().take("team").toObject();

		if(_firstGet){
			if(_userid == team_json.take("chef").toObject().take("user").toObject().take("id").toString().toStdString()){
				_chef = true;
			}

			emit getAll_ended();
			_firstGet = false;
		} else {
			Globals globals;

			auto debut = mcd::explode(team_json.value("creneau").toObject().value("debut").toString().toStdString(), ':');
			auto fin = mcd::explode(team_json.value("creneau").toObject().value("fin").toString().toStdString(), ':');

			globals.startMin = mcd::tof(debut[0]) + mcd::tof(debut[1])/60.0F;
			globals.endMax = mcd::tof(fin[0]) + mcd::tof(fin[1])/60.0F;
			globals.nbHours = mcd::tof(team_json.value("defaultHeures").toString().toStdString());
			globals.workedDays = mcd::vector<std::string>(mcd::arguments["weekdays"]) - mcd::vector<std::string>(mcd::explode(team_json.value("nonTravail").toString().toStdString(), ' '));

			std::vector<TeamMember> members;
			auto teamMembers_json = team_json.take("teamMembers").toArray();
			for(const auto& teamMember_json : teamMembers_json){
				auto days = mcd::explode(teamMember_json.toObject().take("jourDeRepos").toString().toStdString(), ' ');
				std::vector<QString> qdays;

				for(const auto& day : days){
					qdays.push_back(day.c_str());
				}

				TeamMember tm(
					teamMember_json.toObject().value("user").toObject().take("id").toString().toStdString(),
					teamMember_json.toObject().take("nbHeures").toDouble(),
					teamMember_json.toObject().value("user").toObject().take("name").toString(),
					teamMember_json.toObject().value("user").toObject().take("surname").toString(),
					qdays
				);
				members.push_back(tm);
			}

			emit getAll_ended(globals, members, Planning());
		}
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

QJsonObject Api::jsonParse(const std::string& str){
	QString s(str.c_str());
	QJsonDocument json = QJsonDocument::fromJson(s.toUtf8());
	return json.object();
}

void Api::printJsonError(const QJsonObject& json){
	mcd::logs(mcd::Logger::Error, json.value("message").toString().toStdString());
}

QNetworkRequest Api::createRequest(const std::string& url, const std::string& managerName){
	_urls[managerName] = url;
	QNetworkRequest req(QUrl(createUrl(_urls[managerName]).c_str()));

	if(_managers[managerName] == nullptr){
		_managers[managerName] = new QNetworkAccessManager;
		_managers[managerName]->connectToHost(_host.c_str(), 4000);
	}

	return req;
}
