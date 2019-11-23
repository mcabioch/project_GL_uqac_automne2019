/*!
*
*	\file		Entity.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	August, 17 2018
*
*/
#ifndef HEADER_CPP_ENTITY
#define HEADER_CPP_ENTITY

#include "C++/Contraption.hpp"

namespace mcd {
	/*!
	* \class	Entity
	* \brief	An entity
	*/
	class Entity : public Contraption {
		public:
			/* Constructor & Destroyer */
				/*!
				* \brief	Constructor of the class
				*		\param[in]		map			The map where it is
				*		\param[in]		pt			The position in the map
				*		\param[in]		attr		The attributes of the object(width, height, angle)
				*/
				Entity(Map* map = nullptr, Point pt = {0, 0, 0}, ContraptionAttr attr = {0, 0, 0});
				/*! \brief	Virtual destructor */
				virtual ~Entity();

			/* Setters */
				/*!
				* \brief	Set the life of the entity
				*		\param[in]		life			The life to set
				*
				*		\return			void
				*/
				void setLife(double64_t life){ _life = life; }
				/*!
				* \brief	The damages of the entity
				*		\param[in]		damages			The damages to set
				*
				*		\return			void
				*/
				void setDamages(double64_t damages){ _damages = damages; }
				/*!
				* \brief	Set the resistance of the entity
				*		\param[in]		resistance		The resistance to set
				*
				*		\return			void
				*/
				void setResistance(double64_t resistance){ _resistance = resistance; }
				/*!
				* \brief	Set the age of the entity
				*		\param[in]		age				The age to set
				*
				*		\return			void
				*/
				void setAge(double64_t age){ _age = age; }

				/*!
				* \brief	Set the reborn time
				*		\param[in]		reborn			The time to set
				*
				*		\return			void
				*/
				void setReborn(const double64_t reborn){ _reborn = reborn; }
				/*!
				* \brief	Set the actual time
				*		\param[in]		time			The time to set
				*
				*		\return			void
				*/
				void setTimeActReborn(const double64_t time){ _timeActReborn = time; }
				/*!
				* \brief	Set the precedent time
				*		\param[in]		time			The time to set
				*
				*		\return			void
				*/
				void setTimePrecReborn(const double64_t time){ _timePrecReborn = time; }

				/*!
				* \brief	Set the regeneration time
				*		\param[in]		regen			The time to set
				*
				*		\return			void
				*/
				void setRegen(const double64_t regen){ _regen = regen; }
				/*!
				* \brief	Set the actual time
				*		\param[in]		time			The time to set
				*
				*		\return			void
				*/
				void setTimeActRegen(const double64_t time){ _timeActRegen = time; }
				/*!
				* \brief	Set the precedent time
				*		\param[in]		time			The time to set
				*
				*		\return			void
				*/
				void setTimePrecRegen(const double64_t time){ _timePrecRegen = time; }

			/* Getters */
				/*! \return			Return the max life */
				double64_t getLifeMax()const { return _life; }
				/*! \return			Return the damages */
				double64_t getDamages()const { return _damages; }
				/*! \return			Return the resistance */
				double64_t getResistance()const { return _resistance; }
				/*! \return			Return the age */
				double64_t getAge()const { return _age; }

				/*! \return			Return the reborn duration */
				double64_t getReborn()const { return _reborn; }
				/*! \return			Return the actual time since reborn */
				double64_t getTimeActReborn()const { return _timeActReborn; }
				/*! \return			Return the precedent time since reborn */
				double64_t getTimePrecReborn()const { return _timePrecReborn; }

				/*! \return			Return the regen duration */
				double64_t getRegen()const { return _regen; }
				/*! \return			Return the actual time since regen */
				double64_t getTimeActRegen()const { return _timeActRegen; }
				/*! \return			Return the precedet time since regen */
				double64_t getTimePrecRegen()const { return _timePrecRegen; }

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
				* \brief	Grow the entity
				*		\return			void
				*/
				virtual void grow();

				/*! 		\return			Return the actual life */
				double64_t getLife()const { return (_life-_damages < 0)?0:_life-_damages; }

				/*!
				* \brief	Hit an entity with \a damages
				*		\param[in]		damages		The damages to hit
				*
				*		\return			void
				*/
				void hit(double64_t damages);

		protected:

		private:
			double64_t _life;
			double64_t _damages;

			double64_t _resistance;

			double64_t _age;

			double64_t _reborn;
			double64_t _timeActReborn;
			double64_t _timePrecReborn;

			double64_t _regen;
			double64_t _timeActRegen;
			double64_t _timePrecRegen;
	};
}

#endif //HEADER_CPP_ENTITY
