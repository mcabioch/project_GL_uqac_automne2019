/*!
*
*	\file		Args.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\date		November, 13 2019
*
*/
#ifndef HEADER_CPP_ARGS
#define HEADER_CPP_ARGS

#include "C++/Threadable.hpp"

namespace mcd {
	/*!
	* \class		Arguments
	* \brief		A class to manage the arguments
	* \details		This class is usefull to simplify and keep the given arguments
	*/
	class Arguments {
		public:
			/* Constructor et Destroyer */
				/*! \brief	Constructor of the class */
				Arguments() :
					args(),
					indexs(),
					error(),
					_mutex()
				{}
				~Arguments(){}

			/* Setters */
				/*!
				* \brief	Add the arguments of theMay, n to the object
				*		\param[in]		argc		The number of arguments
				*		\param[in]		argv		An array of char*
				*
				*		\return			\b true or \b false
				*/
				bool addProg(int argc, char** argv);
				/*!
				* \brief	Add a value to a part of the array
				*		\param[in]		category	The category in which to add the value
				*		\param[in]		value		The value to add
				*
				*		\return			\b true or \b false
				*/
				template<typename T>
				bool add(const std::string& category, T value){
					_mutex.lock();
						if(contains(indexs, category)){
							auto& cat = args[category];

							cat.push_back(tos(value));
						} else {
							indexs.push_back(category);
							std::vector<std::string> cat;

							cat.push_back(tos(value));

							args[category] = cat;
						}
					_mutex.unlock();

					return true;
				}

			/* Getters */
				/*!
				* \brief	Get the arguments in an index
				*		\param[in]		index		The index of the arguments
				*
				*		\return			Return a vector that contains the arguments
				*/
				std::vector<std::string> operator[](const std::string& index) const;
				/*!
				* \brief	Get the arguments in an index
				*		\param[in]		index		The index of the arguments
				*
				*		\return			Return a vector that contains the arguments
				*/
				std::vector<std::string>& operator[](const std::string& index);

			/* Others */
				/*!
				* \brief	Print all the arguments in the \a index
				*		\param[in]		index		The index of the arguments
				*
				*		\return			void
				*/
				void print(const std::string& index = "") const;

		private:
			std::map<std::string, std::vector<std::string> > args;
			std::vector<std::string> indexs;
			const std::vector<std::string> error;
			mutable mutex _mutex;
	};

	/*! \brief	A global arguments variable to save and keep some arguments */
	extern Arguments arguments;
}

#endif //HEADER_CPP_ARGS
