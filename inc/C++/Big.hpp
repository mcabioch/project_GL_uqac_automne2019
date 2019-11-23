/*!
*
*	\file		Big.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	August, 01 2018 10:15:16
*	\modified	September, 26 2019
*
*/
#ifndef HEADER_BIG
#define HEADER_BIG

#include "C++/OsDetection.hpp"

namespace mcd {
	class Big;

	/*!
	* \brief	Convert a value from something to std::string
	*	\param[in]		in		The value to convert
	*/
	template<typename T>
	std::string toBigVal(T in){
		std::stringstream out;
		out << in;
		return out.str();
	}

	/*!
	* \brief	Convert a char in an int
	*	\param[in]		in		The value to convert
	*/
	int fromBigVal(char in);

	/*!
	* \brief	Convert a std::string in an int
	*	\param[in]		in		The value to convert
	*/
	int fromBigVal(const std::string& in);

	/*!
	* \class	Big
	* \brief	A new huge arithmetic variable
	*
	* \todo		Implement the coma
	*/
	class Big {
		/* Usefull or required defines */
		
		/* Members of Big */
		public:
			/* Internal enums of Big */
			
			/* Constructors & Destructor of Big */
				/*! \brief	The constructor of the class */
				template<typename T, class = std::enable_if_t<std::is_arithmetic<T>::value> >
				explicit Big(T val);
				explicit Big(const std::string& val);
				Big();
				virtual ~Big();

				/*!
				* \brief	The copy constructor of the class
				*	\param[in,out]		other		The class' instance for copying
				*/
				Big(const Big& other);
				/*!
				* \brief	The move constructor of the class
				*	\param[in,out]		other		The class' instance for moving
				*/
				Big(const Big&& other);
			/* Getters of Big */
			
			/* Setters of Big */
			
			/* Statics of Big */
			
			/* Operators of Big */
				/*!
				* \brief	The copy operator of the class
				*	\param[in,out]		other		The class' instance for copying
				*/
				Big& operator=(const Big& other) noexcept;
				/*!
				* \brief	The move operator of the class
				*	\param[in,out]		other		The class' instance for moving
				*/
				Big& operator=(const Big&& other) noexcept;

				Big& operator+=(const Big& other) noexcept;
				Big& operator-=(const Big& other) noexcept;
				Big& operator*=(const Big& other) noexcept;
				Big& operator/=(const Big& other);
				Big& operator%=(const Big& other);

				operator std::string()const noexcept;
				operator bool()const noexcept;

				template<typename T, class = std::enable_if_t<std::is_arithmetic<T>::value> >
				explicit operator T()const noexcept;
			/* Friends of Big */
				friend std::ostream& operator<<(std::ostream& os, const Big& other) noexcept;
				friend std::istream& operator>>(std::istream& is, Big& other) noexcept;

				friend inline Big operator+(const Big& in) noexcept;
				friend inline Big operator-(const Big& in) noexcept;

				/*! \brief	Big + Big */
				friend Big operator+(const Big& a, const Big& b) noexcept;
				/*! \brief	Big - Big */
				friend Big operator-(const Big& a, const Big& b) noexcept;
				/*! \brief	Big * Big */
				friend Big operator*(const Big& a, const Big& b) noexcept;
				/*! \brief	Big / Big */
				friend Big operator/(const Big& a, const Big& b);
				/*! \brief	Big % Big */
				friend Big operator%(const Big& a, const Big& b);

				friend inline Big& operator++(Big& in) noexcept;
				friend inline Big operator++(Big& in, int) noexcept;

				friend inline Big& operator--(Big& in) noexcept;
				friend inline Big operator--(Big& in, int) noexcept;

				/*! \brief	Big == Big */
				friend inline bool operator==(const Big& a, const Big& b) noexcept;
				/*! \brief	Big < Big */
				friend inline bool operator<(const Big& a, const Big& b) noexcept;
				/*! \brief	Big > Big */
				friend bool operator>(const Big& a, const Big& b) noexcept;

				/*! \brief	Big != Big */
				friend inline bool operator!=(const Big& a, const Big& b) noexcept;
				/*! \brief	Big ! Big */
				friend inline bool operator!(const Big& a) noexcept{ return (a == Big(0)); }
				/*! \brief	Big <= Big */
				friend inline bool operator<=(const Big& a, const Big& b) noexcept;
				/*! \brief	Big >= Big */
				friend inline bool operator>=(const Big& a, const Big& b) noexcept;

				/*!
				* \brief	Compute \a a to the power of \a exp
				*	\param[in]		a		The number to compute
				*	\param[in]		exp		The power to use
				*/
				friend Big pow(const Big& a, const Big& exp);
				/*!
				* \brief	Compute a nth root
				*	\param[in]		a		The value to compute
				*	\param[in]		exp		The power of the root
				*/
				friend Big nroot(const Big& a, size_t exp);
				/*!
				* \brief	Compute the pgcd of \a a and \a b
				*	\param[in]		a		The value to use
				*	\param[in]		b		The value to use
				*/
				friend Big pgcd(const Big& a, const Big& b);

				/*!
				* \brief	Compute the invert of the modulo
				*	\param[in]		a		The value to use
				*	\param[in]		b		The value to use
				*/
				friend Big mod(const Big& a, const Big& b);
			/* Others members of Big */
				/*! \brief	Return \b true if the number is a prime number */
				bool prime()const;
				/*! \brief	Return the size of the number */
				size_t size()const {
					return std::string(*this).size();
				}

		protected:
			/* Getters of Big */
			
			/* Setters of Big */
			
			/* Statics of Big */
			
			/* Friends of Big */
			
			/* Others members of Big */
			

		private:
			static void equalize(std::string& val, const std::string& shape);

			/* Compute a nth-root */
				static void nroot(const std::string& val, size_t exp, Big& r);
				static void nthroot(const std::string& val, size_t exp, Big& r, std::vector<std::vector<Big> >& array, std::vector<std::string>& slices);

				static size_t notNull(std::vector<std::vector<Big> >& array, size_t column);
				static bool addZeros(std::vector<std::vector<Big> >& array, const std::string& val, std::vector<std::string>& slices);
			/**********************/

			void set(const std::string& val);
			void minusDivide(Big& val, const Big& other, Big& increment, long int factor);

			Big division(const std::string& val, const Big& dividend, Big& quotient);
			void divide(const std::string& val, const Big& dividend, Big& quotient, Big& rest);

			Big invert()const;

		/* Atttributes of Big */
		public:
			/* Global */
			
			/* Local */
			

		protected:
			/* Global */
			
			/* Local */
			

		private:
			/* Global */
			
			/* Local */
				std::string _val;
				bool _neg;
	};
}

#include "C++/Big_Constructor.hpp"

#include "C++/Big_Operator.hpp"
#include "C++/Big_Comparison.hpp"

#include "C++/Big_Maths.hpp"

#endif //HEADER_BIG
