/*!
*
*	\file		Animal.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	September, 26 2019
*
*/
#ifndef HEADER_CPP_ANIMAL
#define HEADER_CPP_ANIMAL

#include "C++/Hostile.hpp"

namespace mcd {
	/*!
	* \class	Animal
	* \brief	An animal
	*/
	class Animal : public Entity, public Hostile {
		public:
			/* Constructor & Destroyer */
				/*!
				* \brief	Constructor of the class
				*		\param[in]		map			The map where it is
				*		\param[in]		pt			The position in the map
				*		\param[in]		attr		The attributes of the object(width, height, angle)
				*/
				Animal(Map* map = nullptr, Point pt = {0, 0, 0}, ContraptionAttr attr = {0, 0, 0});
				/*! \brief	Virtual destructor */
				virtual ~Animal();

			/* Setters */
				/*!
				* \brief	Set the speed
				*		\param[in]		speed				The value to set
				*
				*		\return			void
				*/
				void setSpeed(const double64_t& speed){ _speed = speed; }

				/*!
				* \brief	Set the food
				*		\param[in]		food				The value to set
				*
				*		\return			void
				*/
				void setFood(const double64_t& food){ _food = food; }
				/*!
				* \brief	Set the maximum food
				*		\param[in]		foodMax				The value to set
				*
				*		\return			void
				*/
				void setFoodMax(const double64_t& foodMax){ _foodMax = foodMax; }

				/*!
				* \brief	Set the species
				*		\param[in]		species				The value to set
				*
				*		\return			void
				*/
				void setSpecies(const std::string& species){ _species = species; }

				/*!
				* \brief	Set the special attack
				*		\param[in]		specialAttack		The value to set
				*
				*		\return			void
				*/
				void setSpecialAttack(const std::string& specialAttack){ _specialAttack = specialAttack; }

			/* Getters */
				/*! \return			Return the speed */
				double64_t getSpeed()const { return _speed; }

				/*! \return			Return the food */
				double64_t getFood()const { return _food; }
				/*! \return			Return the maximum food */
				double64_t getFoodMax()const { return _foodMax; }

				/*! \return			Return the species */
				std::string getSpecies()const { return _species; }

				/*! \return			Return the special attack */
				std::string getSpecialAttack()const { return _specialAttack; }

			/* Friends */

			/* Others */
				/* Collisions */
					/*!
					* \brief	Verify the collisions between two objects like rectangles
					*		\param[in]		other		The obstacle to verify
					*
					*		\return			\b true or \b false
					*/
					bool collidesRect(Contraption& other);
					/*!
					* \brief	Verify the collisions between a circle around this Animal and an other animal
					*		\param[in]		other		The obstacle to verify
					*		\param[in]		radius		The radius for the circle
					*
					*		\return			\b true or \b false
					*/
					bool collidesCircle(Contraption& other, double64_t radius);

					/*!
					* \brief	Verify the collisions between two objects like rectangles
					*		\param[in]		other		The obstacle to verify
					*
					*		\return			\b true or \b false
					*/
					bool collides(Contraption& other){ return collidesRect(other); }

					/*!
					* \brief	Verify the collisions between two objects like rectangles
					*		\param[in]		other		The obstacle to verify
					*
					*		\return			\b true or \b false
					*/
					bool collidesRect(Contraption* other = nullptr);
					/*!
					* \brief	Verify the collisions between a circle around this Animal and an other animal
					*		\param[in]		other		The obstacle to verify
					*		\param[in]		radius		The radius for the circle
					*
					*		\return			\b true or \b false
					*/
					bool collidesCircle(Contraption* other = nullptr, double64_t radius = 0);

					/*!
					* \brief	Verify the collisions between two objects like rectangles
					*		\param[in]		other		The obstacle to verify
					*
					*		\return			\b true or \b false
					*/
					bool collides(Contraption* other = nullptr){ return collidesRect(other); }

					/*!
					* \brief	Take of the obstacle
					* \return			void
					*/
					void anyObstacle(){ _obstacle = nullptr; }
				/**************/

				/*!
				* \brief	Print the infos in the instance of the class in \a stream
				*		\param[in]		stream		The output stream
				*
				*		\return			void
				*/
				virtual void printInfos(std::ostream& stream)const override;

				/*!
				* \brief	Go to the left
				* \return			void
				*/
				void goLeft();
				/*!
				* \brief	Go to the right
				* \return			void
				*/
				void goRight();
				/*!
				* \brief	Go to the top
				* \return			void
				*/
				void goTop();
				/*!
				* \brief	Go to the bot
				* \return			void
				*/
				void goBot();

				/*!
				* \brief	Turn with a given angle
				*		\param[in]		na			The angle to turn to
				*
				*		\return			void
				*/
				void turn(double64_t na);

				/*!
				* \brief	Compute the Z
				*		\param[in]		obj			The obj relative
				*
				*		\return			Return the computed Z of the animal
				*/
				virtual double64_t getRelativeZ(Contraption& obj) override;

				/*!
				* \brief	Move to the actual direction
				* \return			void
				*/
				virtual void move();
				/*!
				* \brief	Move to the direction
				*		\param[in]		dir			The direction where to move
				*
				*		\return			void
				*/
				virtual void move(Direction dir);

				/*!
				* \brief	Attack the target
				*		\param[in]		target			The target for the attack
				*
				*		\return			\b true or \b false
				*/
				virtual bool attack(Entity* target = nullptr) override {
					if(target == nullptr){
						target = getTarget();
					}
					if(target == nullptr){
						return false;
					}

					_attackedSpec = true;

					return true;
				}

		protected:
			Direction _direction;

			bool _movedU;
			bool _movedD;
			bool _movedR;
			bool _movedL;

			std::shared_ptr<Contraption> _obstacle;

		private:
			double64_t _speed;

			double64_t _food;
			double64_t _foodMax;

			std::string _species;
			std::string _specialAttack;
	};
}

#endif //HEADER_CPP_ANIMAL
