/*!
*
*	\file		types.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	November, 09 2019
*
*/
#ifndef HEADER_CPP_TYPES
#define HEADER_CPP_TYPES

#include <typeinfo>

#include "Big.hpp"
#include "C++/Tree.hpp"

#include "PureVirtual.hpp"
#include "UsefullDefines.hpp"

namespace mcd {
	using double32_t = double;
	using double64_t = long double;

	/*! \brief	A container for three values */
	template<typename T, typename U = T, typename V = U>
	class trio{
		public:
			T first;
			U second;
			V ter;
	};

	template<typename T, typename U, typename V>
	bool operator<(const trio<T, U, V>& a, const trio<T, U, V>& b){
		if(a.first < b.first){ return true; }
		if(a.second < b.second){ return true; }
		return a.ter < b.ter;
	}
	template<typename T, typename U, typename V>
	bool operator==(const trio<T, U, V>& a, const trio<T, U, V>& b){
		if(a.first != b.first){ return false; }
		if(a.second != b.second){ return false; }
		return a.ter == b.ter;
	}

	template<typename T, typename U, typename V>
	bool operator>(const trio<T, U, V>& a, const trio<T, U, V>& b){
		return !(a < b) && !(a == b);
	}
	template<typename T, typename U, typename V>
	bool operator>=(const trio<T, U, V>& a, const trio<T, U, V>& b){
		return (a > b) || (a == b);
	}
	template<typename T, typename U, typename V>
	bool operator<=(const trio<T, U, V>& a, const trio<T, U, V>& b){
		return (a < b) || (a == b);
	}
	template<typename T, typename U, typename V>
	bool operator!=(const trio<T, U, V>& a, const trio<T, U, V>& b){
		return !(a == b);
	}

	using trio_str = trio<std::string>;

	/*! \brief	A container for four values */
	template<typename T, typename U = T, typename V = U, typename W = V>
	class quatuor{
		public:
			T first;
			U second;
			V ter;
			W quad;
	};

	template<typename T, typename U, typename V, typename W>
	bool operator<(const quatuor<T, U, V, W>& a, const quatuor<T, U, V, W>& b){
		if(a.first < b.first){ return true; }
		if(a.second < b.second){ return true; }
		if(a.ter < b.ter){ return true; }
		return a.quad < b.quad;
	}
	template<typename T, typename U, typename V, typename W>
	bool operator==(const quatuor<T, U, V, W>& a, const quatuor<T, U, V, W>& b){
		if(a.first != b.first){ return false; }
		if(a.second != b.second){ return false; }
		if(a.ter != b.ter){ return false; }
		return a.quad == b.quad;
	}

	template<typename T, typename U, typename V, typename W>
	bool operator>(const quatuor<T, U, V, W>& a, const quatuor<T, U, V, W>& b){
		return !(a < b) && !(a == b);
	}
	template<typename T, typename U, typename V, typename W>
	bool operator>=(const quatuor<T, U, V, W>& a, const quatuor<T, U, V, W>& b){
		return (a > b) || (a == b);
	}
	template<typename T, typename U, typename V, typename W>
	bool operator<=(const quatuor<T, U, V, W>& a, const quatuor<T, U, V, W>& b){
		return (a < b) || (a == b);
	}
	template<typename T, typename U, typename V, typename W>
	bool operator!=(const quatuor<T, U, V, W>& a, const quatuor<T, U, V, W>& b){
		return !(a == b);
	}

	using quatuor_str = quatuor<std::string>;

	#ifndef DOXYGEN_SHOULD_SKIP_THIS
		namespace {
			template<class C>
			std::string getType(){
				std::string type = __PRETTY_FUNCTION__;

				auto pos = type.find(" = ");
				if(pos != std::string::npos){
					type.erase(0, pos+3);
				}
				pos = type.find(";");
				if(pos != std::string::npos){
					type.erase(type.begin()+pos, type.end());
				}
				pos = type.find("]");
				if(pos != std::string::npos){
					type.erase(type.begin()+pos, type.end());
				}

				std::string first = "> >";
				std::string second = ">>";

				do {
					pos = type.find(first);
					if(pos != std::string::npos){
						type.replace(pos, first.size(), second);
					}
				} while(pos != std::string::npos);

				first = "std::__cxx11::basic_string<char>";
				second = "std::string";
				do {
					pos = type.find(first);
					if(pos != std::string::npos){
						type.replace(pos, first.size(), second);
					}
				} while(pos != std::string::npos);

				return type;
			}
		}
	#endif //DOXYGEN_SHOULD_SKIP_THIS

	/*!
	* \brief	Get the type of \a obj in a string
	*		\return			Return the type of \a obj
	*/
	template<class C>
	std::string getType(const C&){
		return getType<C>();
	}

	/*!
	* \brief	Print the type of \a obj
	*		\param[in]		obj		The variable to print the type of
	*
	*		\return			void
	*/
	template<class C>
	void printType(const C& obj){
		std::cout << "Object type : " << getType(obj) << std::endl;
	}

	/*! \brief	Print the size of \a obj type */
	template<class C>
	void printSize(){
		std::cout << getType<C>() << " : " << sizeof(C) << std::endl;
	}

	/*! \brief	A struct to define a point in space */
	struct Point {
		/*! X position */
		double64_t x = 0;
		/*! Y position */
		double64_t y = 0;
		/*! Z position */
		double64_t z = 0;

		Point top()const {
			return {x, y-1};
		}
		Point bot()const {
			return {x, y+1};
		}
		Point left()const {
			return {x-1, y};
		}
		Point right()const {
			return {x+1, y};
		}

		template<class T, class U>
		typename std::enable_if_t<
									std::is_arithmetic<T>::value &&
									std::is_arithmetic<U>::value
									, Point&>
		operator=(const std::pair<T, U>& o){
			x = static_cast<double64_t>(o.first);
			y = static_cast<double64_t>(o.second);

			return *this;
		}

		template<class T, class U, class V>
		typename std::enable_if_t<
									std::is_arithmetic<T>::value &&
									std::is_arithmetic<U>::value &&
									std::is_arithmetic<V>::value
									, Point&>
		operator=(const trio<T, U, V>& o){
			x = static_cast<double64_t>(o.first);
			y = static_cast<double64_t>(o.second);
			z = static_cast<double64_t>(o.ter);

			return *this;
		}

		friend bool operator==(const Point& a, const Point& b){
			return
				a.x == b.x &&
				a.y == b.y &&
				a.z == b.z;
		}
		friend bool operator!=(const Point& a, const Point& b){
			return !(a == b);
		}
		friend std::ostream& operator<<(std::ostream& os, const Point& a){
			os << a.x << "/" << a.y << "/" << a.z;
			return os;
		}
	};
}

#endif //HEADER_CPP_TYPES
