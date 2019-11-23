/*!
*
*	\file		console.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	October, 03 2019
*
*/
#ifndef HEADER_CPP_CONSOLE
#define HEADER_CPP_CONSOLE

#include "C++/convert.hpp"

namespace mcd {
	/*! \brief	Colors list */
	enum class Colors {
		BLACK_F = 30,
		RED_F = 31,
		GREEN_F = 32,
		YELLOW_F = 33,
		BLUE_F = 34,
		PURPLE_F = 35,
		CYAN_F = 36,
		GREY_F = 37,
		LIGHT_BLACK_F = 90,
		LIGHT_RED_F = 91,
		LIGHT_GREEN_F = 92,
		LIGHT_YELLOW_F = 93,
		LIGHT_BLUE_F = 94,
		LIGHT_PURPLE_F = 95,
		LIGHT_CYAN_F = 96,
		LIGHT_GREY_F = 97,
		BLACK_B = 40,
		RED_B = 41,
		GREEN_B = 42,
		YELLOW_B = 43,
		BLUE_B = 44,
		PURPLE_B = 45,
		CYAN_B = 46,
		GREY_B = 47,
		LIGHT_BLACK_B = 100,
		LIGHT_RED_B = 101,
		LIGHT_GREEN_B = 102,
		LIGHT_YELLOW_B = 103,
		LIGHT_BLUE_B = 104,
		LIGHT_PURPLE_B = 105,
		LIGHT_CYAN_B = 106,
		LIGHT_GREY_B = 107,
		NORMAL = 0,
		BOLD = 1,
		SHADOW = 2,
		ITALIC = 3,
		UNDERLINE = 4,
		INVERT = 7,
		HIDE = 8,
		CROSS = 9
	};

	class Cls;

	/*!
	* \class	Color
	* \brief	Change the text color in the console
	*/
	class Color {
		public:
			/* Constructor */
			/*!
			* \brief	Construct a Color object with a first color
			*/
			explicit Color(const std::string& color);
			virtual ~Color(){}

			/* Variadic template constructor */
			/*!
			* \brief	Construct a Color object with colors
			*/
			template<class ...Args>
			 Color(Colors color, Args... args) :
				code1("\033["),
				colors(""),
				code2("m")
			{
				addColors(color, args...);
			}

			/* Use the class in output stream */
			/*!
			* \brief	Overloading of the << operator
			*/
			friend std::ostream &operator<<(std::ostream &stream, Color const &c);

			/* Last addColors(int) call */
			/*!
			* \brief	Add a color to the object
			*		\param[in]		color		The integer of the color
			*
			*		\return			void
			*/
			void addColors(int color){
				colors += tos(color);
			}
			/* Variadic template addColors(int) member */
			/*!
			* \brief	Add colors to the object
			*		\param[in]		color		One of the colors to add
			*		\param[in]		args		the other colors to add
			*
			*		\return			void
			*/
			template<class ...Args> void addColors(int color, Args... args){
				colors += tos(color) + ";";
				addColors(args...);
			}

			/* Last addColors(Colors) call */
			/*!
			* \brief	Add a color to the object
			*		\param[in]		color		The integer of the color
			*
			*		\return			void
			*/
			void addColors(const Colors& color){
				colors += tos(color);
			}
			/* Variadic template addColors(Colors) member */
			/*!
			* \brief	Add colors to the object
			*		\param[in]		color		One of the colors to add
			*		\param[in]		args		the other colors to add
			*
			*		\return			void
			*/
			template<class ...Args> void addColors(const Colors& color, Args... args){
				colors += tos(color) + ";";
				addColors(args...);
			}

		public:
			friend class Cls;

		private:
			std::string code1;
			std::string colors;
			std::string code2;
	};

	/*!
	* \class	Reinit
	* \brief	Reinit the color in the console
	*/
	class Reinit : public Color {
		public:
			/* Constructor */
			Reinit();
		private:
	};

	/*!
	* \class	Cls
	* \brief	Clear the console
	*/
	class Cls : public Color {
		public:
			/* Constructor */
			Cls();
		private:

	};

	/*!
	* \class	ConsoleCursor
	* \brief	A class to play with the cursor in the console
	* \details	This class allow you to move, save and restore the cursor position
	*/
	class ConsoleCursor : public PureVirtual {
		public:
			/*!
			* \brief	Go to an x/y position
			*		\param[in]		x		The x position
			*		\param[in]		y		The y position
			*
			*		\return			void
			*/
			template<typename T>
			static void goTo(T x, T y){
				std::cout << "\033[" << static_cast<int>(x) << ";" << static_cast<int>(y) << "H";
			}

			/*!
			* \brief	Save the actual cursor position
			*
			*		\return			void
			*/
			static void save();

			/*!
			* \brief	Restore the cursor's saved position
			*
			*		\return			void
			*/
			static void restore();

			/*!
			* \brief	Alias for the restore member
			*
			*		\return			void
			*/
			static void home(){ restore(); }

			/*!
			* \brief	Write something to the given position
			*		\param[in]		str			The string to put in the ostream
			*		\param[in]		x			The x position of the string
			*		\param[in]		y			The y position of the string
			*		\param[in]		color		The color of the string
			*		\return			void
			*/
			template<typename T>
			static void put(const std::string& str, T x, T y, const Color& color = 0){
				ConsoleCursor::save();

				ConsoleCursor::goTo(x, y);
				std::cout << color << str << Reinit();
				fflush(stdout);

				ConsoleCursor::restore();
			}
		private:
	};

	/*!
	* \class	ThreadEndlCout
	* \brief	A class to use std::endl in ThreadCout
	*/
	class ThreadEndlCout {
		public:
			ThreadEndlCout(){}
			virtual ~ThreadEndlCout(){}
	};

	/*!
	* \class	ThreadCout
	* \brief	A class to use std::cout thread safe
	*/
	class ThreadCout : public std::ostream {
		public:
			ThreadCout(){}
			virtual ~ThreadCout(){
				if(_mutexed){
					_mutex.unlock();
				}
			}
			template<class T>
			friend ThreadCout& operator<<(ThreadCout& os, T obj){
				if(!_mutexed){
					_mutex.lock();
					_mutexed = true;
				}
				std::cout << obj;

				return os;
			}
			friend ThreadCout& operator<<(ThreadCout& os, ThreadEndlCout&){
				std::cout << std::endl;
				if(_mutexed){
					_mutexed = false;
					_mutex.unlock();
				}
				return os;
			}

		private:
			static mutex _mutex;
			static bool _mutexed;
	};

	/*! \brief	The thread safe version of std::cout */
	extern ThreadCout cout;

	/*! \brief	The thread safe version of std::endl */
	extern ThreadEndlCout endl;
}

#endif //HEADER_CPP_CONSOLE
