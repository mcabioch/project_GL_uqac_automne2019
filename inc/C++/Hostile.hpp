/*!
*
*	\file		Hostile.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	August, 15 2018
*
*/
#ifndef HEADER_CPP_HOSTILE
#define HEADER_CPP_HOSTILE

#include "C++/Entity.hpp"

namespace mcd {
	/*!
	* \class	Hostile
	* \brief	A class to derivate from when the thing can attack
	*/
	class Hostile {
		public:
			/* Constructor & Destroyer */
				/*! \brief	The constructor of the class */
				Hostile();
				/*! \brief	Virtual destructor */
				virtual ~Hostile();

			/* Setters */
				/*!
				* \brief	Set the Hostile's strength
				*		\param[in]		strength		The new strength
				*
				*		\return			void
				*/
				void setStrength(double64_t strength){ _strength = strength; }
				/*!
				* \brief	Set the Hostile's strength
				*		\param[in]		target			The new target
				*
				*		\return			void
				*/
				void setTarget(Entity* target){ _target.reset(target); }

			/* Getters */
				/*!
				* \brief	Get the Hotsile's strength
				*		\return			Return the strength
				*/
				double64_t getStrength()const { return _strength; }
				/*!
				* \brief	Get the Hotsile's target
				*		\return			Return the target
				*/
				Entity* getTarget()const { return _target.get(); }

			/* Friends */


			/* Others */
				/*!
				* \brief	Print the infos in the instance of the class in \a stream
				*		\param[in]		stream		The output stream
				*
				*		\return			void
				*/
				virtual void printInfos(std::ostream& stream)const;

				/*!
				* \brief	Hurt the target
				*		\param[in]		target			The target to hurt
				*
				*		\return			\b true or \b false
				*/
				bool hurt(Entity* target = nullptr);
				/*!
				* \brief	Attack
				*		\param[in]		target			The target to attack
				*
				*		\return			\b true or \b false
				*/
				virtual bool attack(Entity* target = nullptr) = 0;

				/*!
				* \brief	Set the target to null
				*		\return			void
				*/
				void untarget(){ _target = nullptr; }

		protected:
			std::shared_ptr<Entity> _target;

			bool _attacked;
			bool _attackedSpec;

		private:
			double64_t _strength;
	};
}

#endif //HEADER_CPP_HOSTILE
