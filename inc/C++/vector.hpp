/*!
*
*	\file		vector.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Friday September, 27 2019 00:02:47
*	\modified	Friday September, 27 2019
*
*/
#ifndef HEADER_VECTOR
#define HEADER_VECTOR

#include "C++/arraysIncludes.hpp"

namespace mcd {
	/*!
	* \class	vector
	* \brief	Add some features to std::vector
	*/
	template<class C>
	class vector : public std::vector<C> {
		/* Members of vector */
		public:
			/* Constructor */
				vector() :
					std::vector<C>()
				{}
				explicit vector(const std::vector<C>& v) :
					std::vector<C>(v)
				{}

			/* Operators of vector */
				/*vector<C>& operator=(const std::vector<C>& v){
					*this = v;

					return *this;
				}*/

				vector<C>& operator+=(const vector<C>& b){
					for(const auto& val : b){
						this->push_back(val);
					}

					return *this;
				}

				vector<C> operator+(const vector<C>& b){
					vector<C> c = *this;
					c += b;
					return c;
				}

				vector<C>& operator-=(const vector<C>& b){
					for(const auto& val : b){
						auto it_pos = std::find(this->begin(), this->end(), val);
						if(it_pos != this->end()){
							this->erase(it_pos);
							this->shrink_to_fit();
						}
					}

					return *this;
				}

				vector<C> operator-(const vector<C>& b){
					vector<C> c = *this;
					c -= b;
					return c;
				}

				vector<C>& operator&=(const vector<C>& b){
					*this -= (*this - b);

					return *this;
				}

				vector<C> operator&(const vector<C>& b){
					vector<C> c = *this;
					c &= b;
					return c;
				}

				vector<C>& operator|=(const vector<C>& b){
					*this += b;

					return *this;
				}

				vector<C> operator|(const vector<C>& b){
					vector<C> c = *this;
					c |= b;
					return c;
				}

				vector<C>& operator^=(const vector<C>& b){
					vector<C> inside_b = b;

					inside_b -= *this & b;
					*this -= *this & b;

					*this += inside_b;

					return *this;
				}

				vector<C> operator^(const vector<C>& b){
					vector<C> c = *this;
					c ^= b;
					return c;
				}
			/* Others members of vector */
				/*
				* \brief	Erase an element from a vector on the position pos
				*		\param		a			The array
				*		\param		pos			The position to erase
				*/
				void pop(size_t pos = 0){
					if(pos >= this->size()){ return; }

					this->erase(this->begin() + pos);
				}
	};
}

#endif //HEADER_VECTOR
