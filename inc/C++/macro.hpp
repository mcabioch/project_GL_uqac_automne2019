/*!
*
*	\file		macro.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\date		May, 29 2018
*
*/
#ifndef HEADER_CPP_MACRO
#define HEADER_CPP_MACRO

namespace mcd {
	/*!
	* \brief	A macro to \b create aliases
	*		\param[in]		highLevelF			The alias
	*		\param[in]		lowLevelF			The function
	*/
		#define ALIAS_TEMPLATE_FUNCTION(highLevelF, lowLevelF) \
		template<typename... Args> \
		inline auto highLevelF(Args&&... args) -> decltype(lowLevelF(std::forward<Args>(args)...)) \
		{ \
			return lowLevelF(std::forward<Args>(args)...); \
		}
	/*****************************/
}

#endif //HEADER_CPP_MACRO
