/*!
*
*	\file		Player.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	August, 17 2018
*
*/
#ifndef HEADER_CPP_PLAYER
#define HEADER_CPP_PLAYER

#include "C++/PlayerAbstraction.hpp"
#include "C++/Identifier.hpp"

namespace mcd {
	/*!
	* \class	Player
	* \brief	A player that can be a child from any class
	*/
	template<class PlayerParent>
	class Player : public PlayerAbstraction<PlayerParent>, public Identifier {
		public:
			/* Constructor & Destroyer */
				/*!
				* \brief	Constructor of the class
				*		\param[in]		map			The map where it is
				*		\param[in]		pt			The position in the map
				*		\param[in]		attr		The attributes of the object(width, height, angle)
				*/
				Player(Map* map = nullptr, Point pt = {0, 0, 0}, ContraptionAttr attr = {0, 0, 0}) :
					PlayerAbstraction<PlayerParent>(map, pt, attr)
				{}
				/*! \brief	Virtual destructor */
				virtual ~Player(){}

			/* Others */
				/*!
				* \brief	Print the infos in the instance of the class in \a stream
				*		\param[in]		stream		The output stream
				*
				*		\return			void
				*/
				virtual void printInfos(std::ostream& stream)const override {
					PlayerAbstraction<PlayerParent>::printInfos(stream);
						stream << "\t\t- username : '" << _username << "'" << std::endl;
						stream << "\t\t- password : '";
							if(_password != ""){
								stream << "****";
							}
						stream << "'" << std::endl;
				}
	};
}

#endif //HEADER_CPP_PLAYER
