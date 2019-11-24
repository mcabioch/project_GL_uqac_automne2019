/*!
*
*	\file		Api.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Saturday November, 23 2019 17:04:14
*	\modified	Saturday November, 23 2019
*
*/
#ifndef HEADER_API
#define HEADER_API

#include <QtNetwork>

#include "Globals.h"
#include "Planning.h"
#include "TeamMember.h"

class AuthUser {
	public:
		AuthUser(const std::string& user, const std::string& pass) :
			username(user),
			password(pass)
		{}

		std::string username;
		std::string password;
};

class AuthMember {
	public:
		AuthMember(const std::string& first, const std::string& last, const std::string& days, double hours) :
			firstname(first),
			lastname(last),
			daysOff(days),
			nbHours(hours)
		{}

		std::string firstname;
		std::string lastname;
		std::string daysOff;
		double nbHours;
};

/*!
* \class	Api
* \brief	A class to talk with the remote apis
*/
class Api : public QObject {
	/* Usefull or required defines */
		Q_OBJECT
	/* Members of Api */
	public:
		/* Internal enums of Api */
			
		/* Constructors & Destructor of Api */
			/*! \brief	The constructor of the class */
			Api();
			virtual ~Api();
		/* Getters of Api */
			
		/* Setters of Api */
			
		/* Statics of Api */
			
		/* Operators of Api */
			
		/* Friends of Api */
			
		/* Others members of Api */
			bool connection(const std::string& host);

			void auth(const std::string& user, const std::string& pass);

			void signin(const AuthUser& user, const AuthMember& member, const std::string& teamName);
			void signin(const AuthUser& user, const AuthMember& member);

			void save(const Globals& team, const Planning& planning);
			void saveMembers(const std::vector<TeamMember>& team);
			void deleteMember(const std::string& id);

			void compute();

	public slots:
		void getAll();

		void auth_end(QNetworkReply* reply);
		void register_end(QNetworkReply* reply);
		void signin_end(QNetworkReply* reply);
		void save_end(QNetworkReply* reply);
		void saveMembers_end(QNetworkReply* reply);
		void getAll_end(QNetworkReply* reply);
		void compute_end(QNetworkReply* reply);

	signals:
		void auth_ended();
		void auth_error();

		void signin_ended();
		void signin_error();

		void signin_ended(const std::string& id);
		void signin_error(const std::string& id);

		void save_ended();
		void save_error();

		void saveMembers_ended();
		void saveMembers_error();

		void getAll_ended(const Globals& globals, const std::vector<TeamMember>& teamMembers, const Planning& planning);
		void getAll_error();

		void compute_ended();
		void compute_error();

	protected:
		/* Getters of Api */
			
		/* Setters of Api */
			
		/* Statics of Api */
			
		/* Friends of Api */
			
		/* Others members of Api */
			std::string base64_encode(const std::string& str);

	private:
		std::string createUrl(const std::string& str);

	/* Atttributes of Api */
	public:
		/* Global */
			
		/* Local */
			

	protected:
		/* Global */
			
		/* Local */
			std::map<std::string, QNetworkAccessManager*> _managers;
			std::string _host;

	private:
		/* Global */
			
		/* Local */
			std::string _token;
			std::string _username;
			std::string _teamName;
};

#endif //HEADER_API
