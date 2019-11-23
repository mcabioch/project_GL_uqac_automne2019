/*!
*
*	\file		PlayerAbstraction.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	September, 26 2019
*
*/
#ifndef HEADER_CPP_PLAYER_ABSTRACTION
#define HEADER_CPP_PLAYER_ABSTRACTION

#include "C++/Entities.hpp"

namespace mcd {
	/*!
	* \class	PlayerAbstraction
	* \brief	A player that can be a child from any class
	*/
	template<class PlayerParent>
	class PlayerAbstraction : public PlayerParent {
		public:
			/* Constructor & Destroyer */
				/*!
				* \brief	Constructor of the class
				*		\param[in]		map			The map where it is
				*		\param[in]		pt			The position in the map
				*		\param[in]		attr		The attributes of the object(width, height, angle)
				*/
				PlayerAbstraction(Map* map = nullptr, Point pt = {0, 0, 0}, ContraptionAttr attr = {0, 0, 0}) :
					PlayerParent(map, pt, attr),
					_init(false),
					_paused(false),
					_losted(false),
					_mail(""),
					_experience(0),
					_experienceMax(0)
				{}
				/*! \brief	Virtual destructor */
				virtual ~PlayerAbstraction(){}

			/* Setters */
				/*!
				* \brief	Set the Player'smail
				*		\param[in]		mail				The newmail
				*
				*		\return			void
				*/
				void setMail(const std::string& mail){ _mail = mail; }

				/*!
				* \brief	Set the Player's experience
				*		\param[in]		experience			The new experience
				*
				*		\return			void
				*/
				void setExperience(const double64_t& experience){ _experience = experience; }
				/*!
				* \brief	Set the Player's max experience
				*		\param[in]		experienceMax		The new experience max
				*
				*		\return			void
				*/
				void setExperienceMax(const double64_t& experienceMax){ _experienceMax = experienceMax; }

			/* Getters */
				/*! \return			Return themail */
				std::string getMail()const { return _mail; }

				/*! \return			Return the experience */
				double64_t getExperience()const { return _experience; }
				/*! \return			Return the maximum experience */
				double64_t getExperienceMax()const { return _experienceMax; }

			/* Friends */

			/* Others */
				/*!
				* \brief	Print the infos in the instance of the class in \a stream
				*		\param[in]		stream		The output stream
				*
				*		\return			void
				*/
				virtual void printInfos(std::ostream& stream)const override {
					PlayerParent::printInfos(stream);
					stream << "\tPlayer attributes ;" << std::endl;
						stream << "\t\t- experience : " << _experience << "/" << _experienceMax << std::endl;
				}

				/*!
				* \brief	Pause the player
				*		\return			void
				*/
				void pause(){ _paused = true; }
				/*!
				* \brief	Resume the player
				*		\return			void
				*/
				void resume(){ _paused = false; }
				/*!
				* \brief	Verify if the player is paused
				*		\return			\b true or \b false
				*/
				bool isPaused()const { return _paused; }

				/*!
				* \brief	Lost the focus
				*		\return			void
				*/
				void lost(){ _losted = true; }
				/*!
				* \brief	Regain the focus
				*		\return			void
				*/
				void retreive(){ _losted = false; }
				/*!
				* \brief	Verify if it has the focus
				*		\return			\b true or \b false
				*/
				bool isLost()const { return _losted; }

				/*!
				* \brief	Verify if the player is initialized
				*		\return			\b true or \b false
				*/
				bool isInit()const { return _init; }

		protected:
			bool _init;
			bool _paused;
			bool _losted;

			std::string _mail;

			double64_t _experience;
			double64_t _experienceMax;
	};
}

#endif //HEADER_CPP_PLAYER_ABSTRACTION
