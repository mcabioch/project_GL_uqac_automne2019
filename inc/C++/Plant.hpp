/*!
*
*	\file		Plant.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	August, 17 2018
*
*/
#ifndef HEADER_CPP_PLANT
#define HEADER_CPP_PLANT

#include "C++/Vegetal.hpp"

namespace mcd {
	/*!
	* \class	Plant
	* \brief	A plant
	*/
	class Plant : public Vegetal {
		public:
			/* Constructor & Destroyer */
				/*!
				* \brief	Constructor of the class
				*		\param[in]		map			The map where it is
				*		\param[in]		pt			The position in the map
				*		\param[in]		attr		The attributes of the object(width, height, angle)
				*/
				Plant(Map* map = nullptr, Point pt = {0, 0, 0}, ContraptionAttr attr = {0, 0, 0});
				/*! \brief	Virtual destructor */
				virtual ~Plant();

			/* Setters */

			/* Getters */

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

	};
}

#endif //HEADER_CPP_PLANT
