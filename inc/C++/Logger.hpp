/*!
*
*	\file		Logger.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Saturday November, 09 2019 17:01:15
*	\modified	November, 22 2019
*
*/
#ifndef HEADER_LOGGER
#define HEADER_LOGGER

#include "C++/defines.hpp"

namespace mcd {
	/*!
	* \class	Logger
	* \brief	A class to log some messages
	*/
	class Logger {
		/* Usefull or required defines */
			
		/* Members of Logger */
		public:
			/* Internal enums of Logger */
				enum Level {
					All=0,
					Debug,
					Info,
					Warn,
					Error,
					Fatal,
					Off
				};
			/* Constructors & Destructor of Logger */
				/*! \brief	The constructor of the class */
				Logger();
				/*! \brief	The destructor of the class */
				virtual ~Logger();
			/* Getters of Logger */
				
			/* Setters of Logger */
				
			/* Statics of Logger */
				
			/* Operators of Logger */
				
			/* Friends of Logger */
				
			/* Others members of Logger */
				/*!
				* \brief		Initialize the logger with the logger config file location
				* \details		If the file does not exists, a default file is created.
				* \param[in]	logConfigFile	The logger config file location
				* \return		void
				*/
				void init(const std::string& logConfigFile);

				/*!
				* \brief	Know if the logger is initialized
				* \return	Boolean
				*/
				bool isInit()const { return _initialized; }
				
				/*!
				* \brief		Know if a log Level is enabled or not
				* \param[in]	level	The log Level to test
				* \return		Boolean
				*/
				bool isEnabled(Level level);

				
				/*!
				* \brief		Method to cll to log something
				* \param[in]	level	The Level of the log message
				* \param[in]	line	The line where the log message came from
				* \param[in]	file	The file where the log message came from
				* \param[in]	args	The different parts of the message
				* \return		void
				*/
				template<class ...Args>
				void log(Level level, int line, const std::string& file, Args... args){
					std::lock_guard<std::mutex> lock(_mutex);

					if(!_initialized){
						warning_log(line_number, "Wrong use", "Init the Logger before use it !");
						return;
					}

					if(!isEnabled(level)){
						return;
					}

					std::ofstream write;
					write.open(_logFile.c_str(), std::ios::app);
					if(!write){
						error_log(line_number, "File opening error", "Something went wrong when trying to open, ", _logFile);
					}
					write.close();

					DateTime date;
					std::stringstream sstr;

					sstr << date.get() << " [ ";

					switch(level){
						case Debug:
							sstr << "DEBUG";
							break;
						case Info:
							sstr << "INFO";
							break;
						case Warn:
							sstr << "WARNING";
							break;
						case Error:
							sstr << "ERROR";
							break;
						case Fatal:
							sstr << "FATAL";
							break;
						default:
							break;
					}
					sstr << " ] " << file << ":" << line << " : ";

					intern_log(sstr, args...);

					return;
				}

		protected:
			/* Getters of Logger */
				
			/* Setters of Logger */
				
			/* Statics of Logger */
				
			/* Friends of Logger */
				
			/* Others members of Logger */
				

		private:
			/*!
			* \brief	The copy constructor of the class
			*	\param[in]		other		The class' instance for copying
			*/
			Logger(const Logger& other);
			/*!
			* \brief	The move constructor of the class
			*	\param[in]		other		The class' instance for moving
			*/
			Logger(const Logger&& other);
			/*!
			* \brief	The copy operator of the class
			*	\param[in]		other		The class' instance for copying
			*/
			Logger& operator=(const Logger& other) noexcept;
			/*!
			* \brief	The move operator of the class
			*	\param[in]		other		The class' instance for moving
			*/
			Logger& operator=(const Logger&& other) noexcept;

			void destruct();

			template<class T, class ...Args>
			void intern_log(std::stringstream& sstr, const T& msg, Args... args){
				sstr << msg << " ";

				intern_log(sstr, args...);

				return;
			}

			template<class T, class ...Args>
			void intern_log(std::stringstream& sstr, const T& msg){
				sstr << msg << std::endl;

				std::ofstream write;
				write.open(_logFile.c_str(), std::ios::app);
				write << sstr.str();
				write.close();

				#ifdef DEBUG
					std::cout << sstr.str();
				#endif

				return;
			}

			bool startInit();
			std::vector<std::string> readConfig(const std::string& file);
			void backupLastLogs();

		/* Atttributes of Logger */
		public:
			/* Global */
				
			/* Local */
				

		protected:
			/* Global */
				
			/* Local */
				

		private:
			/* Global */
				
			/* Local */
				static size_t _nbInstance;
				mutex _mutex;
				bool _initialized;

				std::string _logFile;
				Level _printedLevel;
	};

	extern Logger logger;
	#define logs(LEVEL, ...) logger.log(LEVEL, __LINE__, __FILE__, __VA_ARGS__)

	#define debug_log() logs(mcd::Logger::Debug)
	#define debug_logs(...) logs(mcd::Logger::Debug, __VA_ARGS__)
}

#endif //HEADER_LOGGER
