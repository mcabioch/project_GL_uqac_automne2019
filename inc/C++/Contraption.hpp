/*!
*
*	\file		Contraption.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	August, 17 2018
*
*/
#ifndef HEADER_CPP_CONTRAPTION
#define HEADER_CPP_CONTRAPTION

#include "C++/C++.hpp"

namespace mcd {
	/*!
	* \class	Contraption
	* \brief	A contraption
	*/
	class Contraption {
		public:
			/* Constructor & Destroyer */
				/*!
				* \brief	Constructor of the class
				*		\param[in]		map			The map where it is
				*		\param[in]		pt			The position in the map
				*		\param[in]		attr		The attributes of the object(width, height, angle)
				*/
				Contraption(Map* map = nullptr, Point pt = {0, 0, 0}, ContraptionAttr attr = {0, 0, 0});
				/*! \brief	Virtual destructor */
				virtual ~Contraption();

			/* Setters */
				/*!
				* \brief	Set the position
				*		\param[in]		pt				The value to set
				*
				*		\return			void
				*/
				void setPosition(Point pt){ setPosition(pt.x, pt.y, pt.z); }
				/*!
				* \brief	Set the position
				*		\param[in]		x				The x to set
				*		\param[in]		y				The y to set
				*		\param[in]		z				The z to set
				*
				*		\return			void
				*/
				void setPosition(double64_t x, double64_t y, double64_t z = 0);

				/*!
				* \brief	Set the x coordinate
				*		\param[in]		x				The value to set
				*
				*		\return			void
				*/
				void setX(double64_t x);
				/*!
				* \brief	Set the y coordinate
				*		\param[in]		y				The value to set
				*
				*		\return			void
				*/
				void setY(double64_t y);
				/*!
				* \brief	Set the z coordinate
				*		\param[in]		z				The value to set
				*
				*		\return			void
				*/
				void setZ(double64_t z){ _pt.z = z; }

				/*!
				* \brief	Set the attributes
				*		\param[in]		attr			The value to set
				*
				*		\return			void
				*/
				void setAttributes(ContraptionAttr attr){ setAttributes(attr.w, attr.h, attr.angle); }
				/*!
				* \brief	Set the attributes
				*		\param[in]		w				The width to set
				*		\param[in]		h				The height to set
				*		\param[in]		angle			The angle to set
				*
				*		\return			void
				*/
				void setAttributes(double64_t w, double64_t h, double64_t angle = 0);

				/*!
				* \brief	Set the width
				*		\param[in]		w				The value to set
				*
				*		\return			void
				*/
				void setW(double64_t w){ _attr.w = w; }
				/*!
				* \brief	Set the height
				*		\param[in]		h				The value to set
				*
				*		\return			void
				*/
				void setH(double64_t h){ _attr.h = h; }
				/*!
				* \brief	Set the angle
				*		\param[in]		angle			The value to set
				*
				*		\return			void
				*/
				void setA(double64_t angle){ _attr.angle = angle; }

				/*!
				* \brief	Set the map
				*		\param[in]		map				The value to set
				*
				*		\return			void
				*/
				void setMap(Map* map){ _map.reset(map); }

				/*!
				* \brief	Set the level
				*		\param[in]		level			The value to set
				*
				*		\return			void
				*/
				void setLevel(size_t level){ _level = level; }

			/* Getters */
				/*! \return			Return the position */
				Point getPosition()const { return _pt; }

				/*! \return			Return the X position */
				double64_t getX()const { return _pt.x; }
				/*! \return			Return the Y position */
				double64_t getY()const { return _pt.y; }
				/*! \return			Return the Z position */
				double64_t getZ()const { return _pt.z; }

				/*! \return			Return the attributes */
				ContraptionAttr getAttributes()const { return _attr; }

				/*! \return			Return the width */
				double64_t getW()const { return _attr.w; }
				/*! \return			Return the height */
				double64_t getH()const { return _attr.h; }
				/*! \return			Return the angle */
				double64_t getA()const { return _attr.angle; }

				/*! \return			Return the map */
				Map* getMap()const { return _map.get(); }

				/*! \return			Return the level */
				size_t getLevel()const{ return _level; }

			/* Friends */
				/*!
				* \brief	Overload of the << operator
				* \details	Allow you to put a Contraption object in an output stream
				*/
				friend std::ostream& operator<<(std::ostream& stream, Contraption const &in);

			/* Others */
				/*!
				* \brief	Print the infos in the instance of the class in \a stream
				*		\param[in]		stream		The output stream
				*
				*		\return			void
				*/
				virtual void printInfos(std::ostream& stream)const;
				/*!
				* \brief	Compute a z with the obstacles
				*		\param[in]		obj			The obstacle to compute z with
				*
				*		\return			Return the computed z
				*/
				virtual double64_t getRelativeZ(Contraption& obj);

				/*!
				* \brief	Add coordinates to the actual position
				*		\param[in]		x			X coordinate
				*		\param[in]		y			Y coordinate
				*		\param[in]		z			Z coordinate
				*
				*		\return			void
				*/
				void addPosition(double64_t x, double64_t y, double64_t z = 0);
				/*!
				* \brief	Turn the Contraption to the left
				* \return			void
				*/
				void turnLeft(){ setA(getA() - 90); }
				/*!
				* \brief	Turn the Contraption to the right
				* \return			void
				*/
				void turnRight(){ setA(getA() + 90); }

				/*! \brief	Rewrite it to send infos */
				virtual void sender(std::string, vector_str){}

		private:
			std::shared_ptr<Map> _map;

			Point _pt;
			ContraptionAttr _attr;

			size_t _level;
	};
}

#endif //HEADER_CPP_CONTRAPTION
