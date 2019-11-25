/*!
*
*	\file		Binary.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Thursday September, 26 2019 19:42:06
*	\modified	September, 27 2019
*
*/
#ifndef HEADER_BINARY
#define HEADER_BINARY

#include "C++/pointers.hpp"

namespace mcd {
	template <typename T, typename Enable = void>
	class Binary;

	/*!
	* \class	Binary
	* \brief	A class to manage binary values easily
	*/
	template<typename T>
	class Binary<T, typename std::enable_if_t<std::is_arithmetic<T>::value, void>> {
		/* Usefull or required defines */
			
		/* Members of Binary */
		public:
			/* Internal enums of Binary */
				
			/* Constructors & Destructor of Binary */
				/*! \brief	The constructor of the class */
				explicit Binary(const T& in) :
					_in(in)
				{}
				virtual ~Binary(){}
			/* Getters of Binary */
				T get()const { return _in; }
			/* Setters of Binary */
				void set(const T& in){ _in = in; }
			/* Statics of Binary */
				/*!
				* \brief		Print an arithmetic variable value in binary format
				*	\param[in]	in			The value to print
				*	\param[in]	multiple	The number of bits inside a group
				*
				* \return		void
				*/
				static void s_print(const T& in, size_t multiple = 8) {
					Binary b(in);
					b._print(std::cout, multiple);
					std::cout << std::endl;
				}
			/* Operators of Binary */
				Binary<T> operator+(const Binary<T>& b){
					Binary c(*this);
					c += b;
					return c;
				}
				Binary<T>& operator+=(const Binary<T>& b){
					_in += b._in;
					return *this;
				}

				Binary<T> operator-(const Binary<T>& b){
					Binary c(*this);
					c -= b;
					return c;
				}
				Binary<T>& operator-=(const Binary<T>& b){
					_in -= b._in;
					return *this;
				}

				Binary<T> operator*(const Binary<T>& b){
					Binary c(*this);
					c *= b;
					return c;
				}
				Binary<T>& operator*=(const Binary<T>& b){
					_in *= b._in;
					return *this;
				}

				Binary<T> operator/(const Binary<T>& b){
					Binary c(*this);
					c /= b;
					return c;
				}
				Binary<T>& operator/=(const Binary<T>& b){
					_in /= b._in;
					return *this;
				}

				Binary<T> operator%(const Binary<T>& b){
					Binary c(*this);
					c %= b;
					return c;
				}
				Binary<T>& operator%=(const Binary<T>& b){
					_in %= b._in;
					return *this;
				}

				Binary<T> operator&(const Binary<T>& b){
					Binary c(*this);
					c &= b;
					return c;
				}
				Binary<T>& operator&=(const Binary<T>& b){
					_in &= b._in;
					return *this;
				}

				Binary<T> operator|(const Binary<T>& b){
					Binary c(*this);
					c |= b;
					return c;
				}
				Binary<T>& operator|=(const Binary<T>& b){
					_in |= b._in;
					return *this;
				}

				Binary<T> operator^(const Binary<T>& b){
					Binary c(*this);
					c ^= b;
					return c;
				}
				Binary<T>& operator^=(const Binary<T>& b){
					_in ^= b._in;
					return *this;
				}

				Binary<T> operator<<(const Binary<T>& b){
					Binary c(*this);
					c <<= b;
					return c;
				}
				Binary<T>& operator<<=(const Binary<T>& b){
					_in <<= b._in;
					return *this;
				}

				Binary<T> operator>>(const Binary<T>& b){
					Binary c(*this);
					c >>= b;
					return c;
				}
				Binary<T>& operator>>=(const Binary<T>& b){
					_in >>= b._in;
					return *this;
				}


				Binary<T> operator+(const T& b){
					Binary c(*this);
					c += b;
					return c;
				}
				Binary<T>& operator+=(const T& b){
					_in += b;
					return *this;
				}

				Binary<T> operator-(const T& b){
					Binary c(*this);
					c -= b;
					return c;
				}
				Binary<T>& operator-=(const T& b){
					_in -= b;
					return *this;
				}

				Binary<T> operator*(const T& b){
					Binary c(*this);
					c *= b;
					return c;
				}
				Binary<T>& operator*=(const T& b){
					_in *= b;
					return *this;
				}

				Binary<T> operator/(const T& b){
					Binary c(*this);
					c /= b;
					return c;
				}
				Binary<T>& operator/=(const T& b){
					_in /= b;
					return *this;
				}

				Binary<T> operator%(const T& b){
					Binary c(*this);
					c %= b;
					return c;
				}
				Binary<T>& operator%=(const T& b){
					_in %= b;
					return *this;
				}

				Binary<T> operator&(const T& b){
					Binary c(*this);
					c &= b;
					return c;
				}
				Binary<T>& operator&=(const T& b){
					_in &= b;
					return *this;
				}

				Binary<T> operator|(const T& b){
					Binary c(*this);
					c |= b;
					return c;
				}
				Binary<T>& operator|=(const T& b){
					_in |= b;
					return *this;
				}

				Binary<T> operator^(const T& b){
					Binary c(*this);
					c ^= b;
					return c;
				}
				Binary<T>& operator^=(const T& b){
					_in ^= b;
					return *this;
				}

				Binary<T> operator<<(const T& b){
					Binary c(*this);
					c <<= b;
					return c;
				}
				Binary<T>& operator<<=(const T& b){
					_in <<= b;
					return *this;
				}

				Binary<T> operator>>(const T& b){
					Binary c(*this);
					c >>= b;
					return c;
				}
				Binary<T>& operator>>=(const T& b){
					_in >>= b;
					return *this;
				}
			/* Friends of Binary */
				friend std::ostream& operator<<(std::ostream& os, const Binary& b) {
					b._print(os);
					return os;
				}
			/* Others members of Binary */
				/*!
				* \brief		Print the value in binary format
				*	\param[in]	multiple	The number of bits inside a group
				*
				* \return		void
				*/
				void print(size_t multiple = 8) const {
					_print(std::cout, multiple);
					std::cout << std::endl;
				}

		protected:
			/* Getters of Binary */
				
			/* Setters of Binary */
				
			/* Statics of Binary */
				
			/* Friends of Binary */
				
			/* Others members of Binary */
				

		private:
			void _print(std::ostream& os, size_t multiple = 8) const {
				T mask = 1;

				for(size_t i = sizeof(T)*8; i > 0; --i){
					if(multiple && !(i%multiple) && i != sizeof(T)*8){
						os << " ";
					}

					os << ((_in & (mask << (i-1)))?1:0);
				}
			}

		/* Atttributes of Binary */
		public:
			/* Global */
				
			/* Local */
				

		protected:
			/* Global */
				
			/* Local */
				

		private:
			/* Global */
				
			/* Local */
				T _in;
	};
}

#endif //HEADER_BINARY
