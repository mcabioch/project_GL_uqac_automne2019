/*!
*
*	\file		Vegetal.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	August, 17 2018
*
*/
#ifndef HEADER_CPP_VEGETAL
#define HEADER_CPP_VEGETAL

#include "C++/Entity.hpp"

namespace mcd {
	/*!
	* \class	Vegetal
	* \brief	A vegetal
	*/
	class Vegetal : public Entity {
		public:
			/* Constructor & Destroyer */
				/*!
				* \brief	Constructor of the class
				*		\param[in]		map			The map where it is
				*		\param[in]		pt			The position in the map
				*		\param[in]		attr		The attributes of the object(width, height, angle)
				*/
				Vegetal(Map* map = nullptr, Point pt = {0, 0, 0}, ContraptionAttr attr = {0, 0, 0});
				/*! \brief	Virtual destructor */
				virtual ~Vegetal();

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
				/*!
				* \brief	Cut the plant to have twice
				*		\param[in]		percent		The percent of cut
				*
				*		\return			Return a pointer to the child plant
				*/
				virtual Vegetal* cut(double64_t percent = 100);

		protected:

		private:

	};
}

#endif //HEADER_CPP_VEGETAL
