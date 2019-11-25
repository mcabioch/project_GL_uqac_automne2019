/*!
*
*	\file		Ant.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	August, 17 2018
*
*/
#ifndef HEADER_CPP_ANT
#define HEADER_CPP_ANT

#include "C++/Animal.hpp"

namespace mcd {
	/*!
	* \class	Ant
	* \brief	An ant
	*/
	class Ant : public Animal {
		public:
			/* Constructor & Destroyer */
				/*!
				* \brief	Constructor of the class
				*		\param[in]		map			The map where it is
				*		\param[in]		pt			The position in the map
				*		\param[in]		attr		The attributes of the object(width, height, angle)
				*/
				Ant(Map* map = nullptr, Point pt = {0, 0, 0}, ContraptionAttr attr = {0, 0, 0});
				/*! \brief	Virtual destructor */
				virtual ~Ant();

			/* Setters */
				/*!
				* \brief	Set the caste of the ant
				*		\param[in]		caste			The caste to set
				*
				*		\return			void
				*/
				void setCaste(const std::string& caste){ _caste = caste; }

				/*!
				* \brief	Se the stone for the ant
				*		\param[in]		stone			The stone to set
				*
				*		\return			void
				*/
				void setStone(const double64_t& stone){ _stone = stone; }
				/*!
				* \brief	Set the maximum stone for the ant
				*		\param[in]		stoneMax		The maximum stone to set
				*
				*		\return			void
				*/
				void setStoneMax(const double64_t& stoneMax){ _stoneMax = stoneMax; }

			/* Getters */
				/*! \return			Return the caste */
				std::string getCaste()const { return _caste; }

				/*! \return			Return the stone */
				double64_t getStone()const { return _stone; }
				/*! \return			Return the maximum stone */
				double64_t getStoneMax()const { return _stoneMax; }

			/* Friends */

			/* Others */
				/*!
				* \brief	Print the infos in the instance of the class in \a stream
				*		\param[in]		stream		The output stream
				*
				*		\return			void
				*/
				virtual void printInfos(std::ostream& stream)const override;

		protected:

		private:
			std::string _caste;

			double64_t _stone;
			double64_t _stoneMax;
	};
}

#endif //HEADER_CPP_ANT
