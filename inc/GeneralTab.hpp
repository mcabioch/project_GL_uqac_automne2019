/*!
*
*	\file		GeneralTab.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Saturday November, 23 2019 15:07:37
*	\modified	Saturday November, 23 2019
*
*/
#ifndef HEADER_GENERAL_TAB
#define HEADER_GENERAL_TAB

#include "includes.h"

#include "Globals.h"
#include "TeamMember.h"
#include "Planning.h"

/*!
* \class	GeneralTab
* \brief	
*/
class GeneralTab {
	/* Usefull or required defines */
		
	/* Members of GeneralTab */
	public:
		/* Internal enums of GeneralTab */
			
		/* Constructors & Destructor of GeneralTab */
			/*! \brief	The constructor of the class */
			GeneralTab();
			virtual ~GeneralTab();

			/*!
			* \brief	The copy constructor of the class
			*	\param[in]		other		The class' instance for copying
			*/
			GeneralTab(const GeneralTab& other);
			/*!
			* \brief	The move constructor of the class
			*	\param[in]		other		The class' instance for moving
			*/
			GeneralTab(const GeneralTab&& other);
		/* Getters of GeneralTab */
			
		/* Setters of GeneralTab */
			
		/* Statics of GeneralTab */
			
		/* Operators of GeneralTab */
			/*!
			* \brief	The copy operator of the class
			*	\param[in]		other		The class' instance for copying
			*/
			GeneralTab& operator=(const GeneralTab& other) noexcept;
			/*!
			* \brief	The move operator of the class
			*	\param[in]		other		The class' instance for moving
			*/
			GeneralTab& operator=(const GeneralTab&& other) noexcept;
		/* Friends of GeneralTab */
			
		/* Others members of GeneralTab */
			

	protected:
		/* Getters of GeneralTab */
			
		/* Setters of GeneralTab */
			
		/* Statics of GeneralTab */
			
		/* Friends of GeneralTab */
			
		/* Others members of GeneralTab */
			

	private:
		

	/* Atttributes of GeneralTab */
	public:
		/* Global */
			
		/* Local */
			

	protected:
		/* Global */
			
		/* Local */
			

	private:
		/* Global */
			
		/* Local */
			
};

#endif //HEADER_GENERAL_TAB
