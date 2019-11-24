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
			void signin(){}

	public slots:
		void auth_end(QNetworkReply* reply);

	signals:
		void auth_ended();
		void auth_error();

	protected:
		/* Getters of Api */
			
		/* Setters of Api */
			
		/* Statics of Api */
			
		/* Friends of Api */
			
		/* Others members of Api */
			std::string base64_encode(const std::string& str);

	private:
		

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
};

#endif //HEADER_API
