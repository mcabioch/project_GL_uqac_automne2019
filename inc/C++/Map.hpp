/*!
*
*	\file		Map.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	July, 29 2018 14:27:51
*	\modified	September, 26 2019
*
*/
#ifndef HEADER_CPP_MAP
#define HEADER_CPP_MAP

#include "C++/PathfindingAlgorithms.hpp"

namespace mcd {
	/*!
	* \brief	Tiles of the map
	*/
	enum class Tile {
		NONE = 0,
		OBSTACLE,
		GROUND,
		ERROR
	};

	/*!
	* \brief	An object to group the dimensions of the world
	*/
	struct WorldDimensions {
		size_t w = 0;
		size_t h = 0;
		size_t z = 0;
	};

	/*! \brief	A struct to know informations about th movement of something in the map */
	struct MapMove {
		bool next = false;
		bool end = false;
	};

	using MapLine = std::vector<Tile>;
	using MapArray = std::vector<MapLine>;

	/*!
	* \class	Map
	* \brief	A class to manage a map and that implement some pathfinding algorithms
	*/
	class Map {
		/* Members of Map */
		public:
			/* Constructors & Destructor of Map */
				/*!
				* \brief	The constructor of the map that initialize it
				*		\param[in]		dimensions		The dimensions of the map
				*/
				explicit Map(WorldDimensions dimensions);
				virtual ~Map();
			/* Getters of Map */
				/*! \return			Return the size */
				WorldDimensions getSize()const { return WorldDimensions{_w, _h}; }
				/*! \return			Return the width */
				size_t getW()const { return _w; }
				/*! \return			Return the height */
				size_t getH()const { return _h; }
			
				PathfindingProblem getProblem();

				/*! \return			Return the maparray */
				MapArray get()const { return _map; }
			/* Setters of Map */
				/*!
				* \brief	Set new dimensions for the map
				*		\param[in]		dimensions		The dimensions of the map
				*
				*		\return			void
				*/
				void setSize(WorldDimensions dimensions);
				/*!
				* \brief	Set a new width for the map
				*		\param[in]		w				The width of the map
				*
				*		\return			void
				*/
				void setW(size_t w);
				/*!
				* \brief	Set a new height for the map
				*		\param[in]		h				The height of the map
				*
				*		\return			void
				*/
				void setH(size_t h);
			/* Statics of Map */
			
			/* Operators of Map */
				/*!
				* \brief	Overloading of the () operator
				*		\param[in]		i			The x coordinate of the Tile
				*		\param[in]		j			The y coordinate of the Tile
				*
				*		\return			Return a Tile of the map
				*/
				Tile& operator()(size_t i, size_t j);
				/*!
				* \brief	Overloading of the () operator
				*		\param[in]		i			The x coordinate of the Tile
				*		\param[in]		j			The y coordinate of the Tile
				*
				*		\return			Return a Tile of the map
				*/
				Tile operator()(size_t i, size_t j) const;
			/* Friends of Map */
			
			/* Others members of Map */
				/*!
				* \brief	Clear the map array
				*		\return			void
				*/
				void clear();
				/*!
				* \brief	Print the map in the console
				*		\return			void
				*/
				void consolePrint();

				/*!
				* \brief	Verify if the point is in map on X axis
				*		\param[in]		pt			The x coordinate
				*		\param[in]		dim			The width of the object
				*
				*		\return			\b true or \b false
				*/
				bool isXIn(double64_t pt, double64_t dim);
				/*!
				* \brief	Verify if the point is in map on Y axis
				*		\param[in]		pt			The y coordinate
				*		\param[in]		dim			The height of the object
				*
				*		\return			\b true or \b false
				*/
				bool isYIn(double64_t pt, double64_t dim);

				/*!
				* \brief	Load the map from a file
				*		\param[in]		file		The file to load from
				*
				*		\return			\b true or \b false
				*/
				bool load(const std::string& file);
				/*!
				* \brief	Save the map in a file
				*		\param[in]		file		The file to save in
				*
				*		\return			\b true or \b false
				*/
				bool save(const std::string& file)const;

				/*!
				* \brief	Put an entity on the given position
				*		\param[out]		id		The id for the entity in the map
				*		\param[in]		x		The x position of the entity
				*		\param[in]		y		The y position of the entity
				*		\param[in]		w		The width of the entity
				*		\param[in]		h		The height of the entity
				*
				*		\return			Return true if the entity has been added to the map
				*/
				bool putEntity(size_t& id, double64_t x, double64_t y, double64_t w, double64_t h);
				/*!
				* \brief	Move an entity from the first position to the second position
				*		\param[in]		id		The id of the entity in the map
				*		\param[in]		path	The path to follow
				*		\param[in]		x		The new x position of the entity
				*		\param[in]		y		The new y position of the entity
				*
				*		\return			Return a MapMove, .next to know if it can continue, .end to know if it's the end
				*/
				MapMove moveEntity(size_t id, Path& path, double64_t x, double64_t y);
				/*!
				* \brief	Move an entity to the given position
				*		\param[in]		id		The id of the entity in the map
				*		\param[in]		x		The new x position of the entity
				*		\param[in]		y		The new y position of the entity
				*
				*		\return			Return void
				*/
				void setEntity(size_t id, double64_t x, double64_t y);
				/*!
				* \brief	Verify if a position on the map is a ground tileor another one
				*		\param[in]		pt		Thepoint where to verify
				*
				*		\return			Return \b true or \b false
				*/
				bool isFree(const Point& pt);

				/*!
				* \brief	Verify if an entity is on the ground or not
				*		\param[in]		id		The id of the entity in the map
				*
				*		\return			Return \b true or \b false
				*/
				bool isOnGround(size_t id){
					return isFree(_entities[id].first);
				}
				/*!
				* \brief	Verify if a point is on the ground or not
				*		\param[in]		pt		The point to test
				*
				*		\return			Return \b true or \b false
				*/
				bool isOnGround(const Point& pt){
					return isFree(pt);
				}

				/*!
				* \brief	Compute a path from the entity position to the point
				*		\param[in]		id			The id of the entity
				*		\param[in]		dest		The point to join
				*
				*		\return			Return the computed Dijkstra path
				*/
				Path dijkstra(size_t id, Point dest);
				/*!
				* \brief	Compute a path between two points
				*		\param[in]		origin		The point where to start
				*		\param[in]		dest		The point to join
				*
				*		\return			Return the computed Dijkstra path
				*/
				Path dijkstra(Point origin, Point dest);

				//Path anthill(size_t id, Point dest);
				//Path anthill(Point origin, Point dest);

				//Path aStar(size_t id, Point dest);
				//Path aStar(Point origin, Point dest);

				/* Path simulation */
					/*!
					* \brief	Test a complete path on the map in the console
					*		\param[in]		path		The path to follow
					*		\param[in]		show		\b true or \b false
					*		\param[in]		color		The color ofthe path
					*/
					MapMove testPath(Path& path, bool show = false, Color color = Colors::PURPLE_B);
					/*!
					* \brief	Reset the path's simulation
					*		\param[in]		path		The path to follow
					*/
					void resetSim(Path& path);
				/*******************/

		protected:
			/* Getters of Map */
			
			/* Setters of Map */
			
			/* Statics of Map */
			
			/* Friends of Map */
			
			/* Others members of Map */
			

		private:
			bool printEntity(size_t x, size_t y)const;
			void validArrival(const Point& from, Point& to);

		/* Atttributes of Map */
		public:
			/* Global */
			
			/* Local */
			

		protected:
			/* Global */
			
			/* Local */
			

		private:
			/* Global */
			
			/* Local */
				Tile _errorTile;

				size_t _w;
				size_t _h;

				MapArray _map;
				std::vector<std::pair<Point, Point> > _entities;

				bool _printed;
	};
}

#endif //HEADER_CPP_MAP
