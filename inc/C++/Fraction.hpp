/*!
*
*	\file		Fraction.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Monday September, 16 2019 17:05:47
*	\modified	September, 26 2019
*
*/
#ifndef HEADER_FRACTION
#define HEADER_FRACTION

#include "C++/maths.hpp"
#include <iomanip>

namespace mcd {
	/*!
	* \class	Fraction
	* \brief	A class to manage fractions
	*/
	class Fraction {
		/* Members of Fraction */
		public:
			/* Constructors & Destructor of Fraction */
				/*! \brief	The constructor of the class */
				Fraction();
				explicit Fraction(double value);
				Fraction(long num, long denom);
				virtual ~Fraction();
			/* Getters of Fraction */
				long numerator()const { return _numerator; }
				long denominator()const { return _denominator; }
			/* Operators of Fraction */
				Fraction& operator+=(const Fraction& b);
				Fraction operator+(const Fraction& b)const;

				Fraction& operator-=(const Fraction& b);
				Fraction operator-(const Fraction& b)const;

				Fraction& operator*=(const Fraction& b);
				Fraction operator*(const Fraction& b)const;

				Fraction& operator/=(const Fraction& b);
				Fraction operator/(const Fraction& b)const;

				Fraction& operator%=(const Fraction& b);
				Fraction operator%(const Fraction& b)const;

				bool operator==(const Fraction& b)const;
				bool operator>(const Fraction& b)const;
				bool operator<(const Fraction& b)const;

				bool operator!=(const Fraction& b)const;
				bool operator>=(const Fraction& b)const;
				bool operator<=(const Fraction& b)const;

				Fraction& operator++();
				Fraction& operator--();

				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				Fraction& operator+=(const T& b){
					*this += Fraction(static_cast<double>(b));
					return *this;
				}
				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				Fraction operator+(const T& b){
					return (*this + Fraction(static_cast<double>(b)));
				}

				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				Fraction& operator-=(const T& b){
					*this -= Fraction(static_cast<double>(b));
					return *this;
				}
				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				Fraction operator-(const T& b){
					return (*this - Fraction(static_cast<double>(b)));
				}

				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				Fraction& operator*=(const T& b){
					*this *= Fraction(static_cast<double>(b));
					return *this;
				}
				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				Fraction operator*(const T& b){
					return (*this * Fraction(static_cast<double>(b)));
				}

				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				Fraction& operator/=(const T& b){
					*this /= Fraction(static_cast<double>(b));
					return *this;
				}
				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				Fraction operator/(const T& b){
					return (*this / Fraction(static_cast<double>(b)));
				}

				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				Fraction& operator%=(const T& b){
					*this %= Fraction(static_cast<double>(b));
					return *this;
				}
				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				Fraction operator%(const T& b){
					return (*this % Fraction(static_cast<double>(b)));
				}

				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				bool operator==(const T& b){
					return (*this == Fraction(static_cast<double>(b)));
				}
				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				bool operator>(const T& b){
					return (*this > Fraction(static_cast<double>(b)));
				}
				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				bool operator<(const T& b){
					return (*this < Fraction(static_cast<double>(b)));
				}

				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				bool operator!=(const T& b){
					return (*this != Fraction(static_cast<double>(b)));
				}
				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				bool operator>=(const T& b){
					return (*this >= Fraction(static_cast<double>(b)));
				}
				template<typename T, class = typename std::enable_if<std::is_arithmetic<T>::value>::type>
				bool operator<=(const T& b){
					return (*this <= Fraction(static_cast<double>(b)));
				}

				operator double()const { return static_cast<double>(_numerator) / static_cast<double>(_denominator); }
			/* Friends of Fraction */
				friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
			/* Others members of Fraction */
				

		private:
			void init(double value);
			void reduice();

			size_t findPeriod(double value);
			bool hasPeriod(double value);

			std::string tos(double value);

		/* Atttributes of Fraction */
		private:
			/* Local */
				long _numerator;
				long _denominator;

				std::string _shape;
	};
}

#endif //HEADER_FRACTION
