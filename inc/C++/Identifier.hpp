/*!
*
*	\file		Identifier.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	September, 26 2019
*
*/
#ifndef HEADER_CPP_IDENTIFIER
#define HEADER_CPP_IDENTIFIER

#include "C++/C++.hpp"

namespace mcd {
	/*!
	* \class	Identifier
	* \brief	A class to store some identify datas
	*/
	class Identifier {
		public:
			/* Constructor & Destructor */
				Identifier() :
					_username(""),
					_password(""),
					_id(0)
				{}
				virtual ~Identifier(){}
			/* Setters */
				/*!
				* \brief	Set the Player's username
				*		\param[in]		username			The new username
				*
				*		\return			void
				*/
				void setUsername(const std::string& username){ _username = username; }
				/*!
				* \brief	Set the Player's password
				*		\param[in]		password			The new password
				*
				*		\return			void
				*/
				void setPassword(const std::string& password){ _password = password; }

				/*!
				* \brief	Set the Player's id
				*		\param[in]		id					The new id
				*
				*		\return			void
				*/
				void setId(size_t id){ _id = id; }

			/* Getters */
				/*! \return			Return the username */
				std::string getUsername()const { return _username; }
				/*! \return			Return the password */
				std::string getPassword()const { return _password; }

				/*! \return			Return the id */
				virtual size_t getId()const { return _id; }

			/* Friends */

			/* Others */

		protected:
			std::string _username;
			std::string _password;

			size_t _id;
	};
}

#endif //HEADER_CPP_IDENTIFIER
