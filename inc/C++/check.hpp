/*!
*
*	\file		check.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	November, 12 2019
*
*/
#ifndef HEADER_CPP_CHECK
#define HEADER_CPP_CHECK

#include <memory>
#include <chrono>

#include "C++/vector.hpp"
#include "C++/collides.hpp"

#ifdef OS_WINDOWS
	#include "boost/chrono.hpp"

	namespace mcd {
		namespace this_thread {
			template<typename TimeDuration>
			void yield() noexcept{
				boost::this_thread::yield();
			}

			template <class Rep>
			void sleep_for(const std::chrono::duration<Rep, std::nano>& rel_time){
				boost::this_thread::sleep_for(boost::chrono::duration<Rep, boost::nano>(rel_time.count()));
			}
			template <class Rep>
			void sleep_for(const std::chrono::duration<Rep, std::micro>& rel_time){
				boost::this_thread::sleep_for(boost::chrono::duration<Rep, boost::micro>(rel_time.count()));
			}
			template <class Rep>
			void sleep_for(const std::chrono::duration<Rep, std::milli>& rel_time){
				boost::this_thread::sleep_for(boost::chrono::duration<Rep, boost::milli>(rel_time.count()));
			}
			template <class Rep>
			void sleep_for(const std::chrono::duration<Rep, std::centi>& rel_time){
				boost::this_thread::sleep_for(boost::chrono::duration<Rep, boost::centi>(rel_time.count()));
			}
			template <class Rep>
			void sleep_for(const std::chrono::duration<Rep, std::deci>& rel_time){
				boost::this_thread::sleep_for(boost::chrono::duration<Rep, boost::deci>(rel_time.count()));
			}
			template <class Rep>
			void sleep_for(const std::chrono::duration<Rep, std::ratio<1>>& rel_time){
				boost::this_thread::sleep_for(boost::chrono::duration<Rep, boost::ratio<1>>(rel_time.count()));
			}
			template <class Rep>
			void sleep_for(const std::chrono::duration<Rep, std::deca>& rel_time){
				boost::this_thread::sleep_for(boost::chrono::duration<Rep, boost::deca>(rel_time.count()));
			}
			template <class Rep>
			void sleep_for(const std::chrono::duration<Rep, std::hecto>& rel_time){
				boost::this_thread::sleep_for(boost::chrono::duration<Rep, boost::hecto>(rel_time.count()));
			}
			template <class Rep>
			void sleep_for(const std::chrono::duration<Rep, std::kilo>& rel_time){
				boost::this_thread::sleep_for(boost::chrono::duration<Rep, boost::kilo>(rel_time.count()));
			}
		}
	}
#else
	namespace mcd {
		namespace this_thread {
			template<typename TimeDuration>
			void yield() noexcept{
				std::this_thread::yield();
			}

			template <class Rep, class Period>
			void sleep_for(const std::chrono::duration<Rep, Period>& rel_time){
				std::this_thread::sleep_for(rel_time);
			}
		}
	}
#endif

namespace mcd {
	using pair_str = std::pair<std::string, std::string>;

	namespace Check {
		/*! \brief	A template class to test if T is a vector */
		template<typename T>
		class is_vector{
			public:
				const static bool value = false;
		};

		#ifndef DOXYGEN_SHOULD_SKIP_THIS
			template<typename T>
			class is_vector<std::vector<T>>{
				public:
					const static bool value = true;
			};

			template<typename T>
			class is_vector<mcd::vector<T>>{
				public:
					const static bool value = true;
			};
		#endif //DOXYGEN_SHOULD_SKIP_THIS

		/*! \brief	A template class to test if T is an array, a vector or a map */
		template<typename T>
		class is_array{
			public:
				const static bool value = is_vector<T>::value;
		};

		#ifndef DOXYGEN_SHOULD_SKIP_THIS
			template<typename T>
			class is_array<std::deque<T>>{
				public:
					const static bool value = true;
			};

			template<typename T, typename U>
			class is_array<std::map<T, U>>{
				public:
					const static bool value = true;
			};

			template<typename T, std::size_t U>
			class is_array<std::array<T, U>>{
				public:
					const static bool value = true;
			};
		#endif //DOXYGEN_SHOULD_SKIP_THIS

		/*! \brief	A template class to test if T is a std::pair */
		template<typename T>
		class is_pair{
			public:
				const static bool value = false;
		};

		#ifndef DOXYGEN_SHOULD_SKIP_THIS
			template<typename T, typename U>
			class is_pair<std::pair<T, U>>{
				public:
					const static bool value = true;
			};
		#endif //DOXYGEN_SHOULD_SKIP_THIS

		/*! \brief	A template class to test if T is a std::pair */
		template<typename T>
		class is_trio{
			public:
				const static bool value = false;
		};

		#ifndef DOXYGEN_SHOULD_SKIP_THIS
			template<typename T, typename U, typename V>
			class is_trio<trio<T, U, V>>{
				public:
					const static bool value = true;
			};
		#endif //DOXYGEN_SHOULD_SKIP_THIS

		/*! \brief	A template class to test if T is a std::pair */
		template<typename T>
		class is_quatuor{
			public:
				const static bool value = false;
		};

		#ifndef DOXYGEN_SHOULD_SKIP_THIS
			template<typename T, typename U, typename V, typename W>
			class is_quatuor<quatuor<T, U, V, W>>{
				public:
					const static bool value = true;
			};
		#endif //DOXYGEN_SHOULD_SKIP_THIS

		/*! \brief	A template class to test if T is a std::string */
		template<typename T>
		class is_string{
			public:
				const static bool value = false;
		};

		#ifndef DOXYGEN_SHOULD_SKIP_THIS
			template<>
			class is_string<std::string>{
				public:
					const static bool value = true;
			};
		#endif //DOXYGEN_SHOULD_SKIP_THIS

		/*! \brief	A template class to test if T is a string regex match */
		template<typename T>
		class is_smatch{
			public:
				const static bool value = false;
		};

		#ifndef DOXYGEN_SHOULD_SKIP_THIS
			template<>
			class is_smatch<std::smatch>{
				public:
					const static bool value = true;
			};
		#endif //DOXYGEN_SHOULD_SKIP_THIS

		/*! \brief	A template class to test if T is a chrono::duration */
		template<class T>
		class is_duration {
			public:
				const static bool value = false;
		};

		#ifndef DOXYGEN_SHOULD_SKIP_THIS
			template<class Rep, class Period>
			class is_duration<std::chrono::duration<Rep, Period>> {
				public:
					const static bool value = true;
			};
		#endif //DOXYGEN_SHOULD_SKIP_THIS

		/*! \brief	Verify if an object has the given method */
		#define has_method(meth, func)\
		template<typename T>\
		class func {\
			private:\
				typedef std::true_type yes;\
				typedef std::false_type no;\
	\
				template<typename U>\
				static auto test(int) -> decltype(std::declval<U>().meth() == 1, yes());\
				template<typename>\
				static no test(...);\
	\
			public:\
				func(){}\
				virtual ~func(){}\
	\
				static constexpr bool value = std::is_same<decltype(test<T>(0)), yes>::value;\
		}

		/*! \brief	Verify if an object has a size method */
		has_method(size, has_size_method);

		/*! \brief	A template class to test if T has an ostream operator */
		template<typename T>
		class has_ostream_operator {
			private:
				typedef std::true_type yes;
				typedef std::false_type no;
				static std::ostream& s;

				template<typename TT, typename SS>
				static auto test(SS&& s, TT&& t) -> decltype(s << t);
			
				struct dummy_t {};
				static dummy_t test(...);

				using return_type = decltype(test(s, std::declval<T>()));

			public:
				has_ostream_operator(){};
				virtual ~has_ostream_operator(){}

				static constexpr bool value = !std::is_same<return_type, dummy_t>::value;
		};

		/*! \brief	A template class to test if T has an istream operator */
		template<typename T>
		class has_istream_operator {
			private:
				typedef std::true_type yes;
				typedef std::false_type no;
				static std::istream& s;

				template<typename TT, typename SS>
				static auto test(SS&& s, TT&& t) -> decltype(s >> t);
			
				struct dummy_t {};
				static dummy_t test(...);

				using return_type = decltype(test(s, std::declval<T>()));

			public:
				has_istream_operator(){};
				virtual ~has_istream_operator(){}

				static constexpr bool value = !std::is_same<return_type, dummy_t>::value;
		};

		/*! \brief	A template class to test if T is printable */
		template<typename T>
		class is_printable{
			public:
				const static bool value = has_ostream_operator<T>::value;
		};

		#ifndef DOXYGEN_SHOULD_SKIP_THIS
			template<>
			class is_printable<std::string>{
				public:
					const static bool value = true;
			};
		#endif //DOXYGEN_SHOULD_SKIP_THIS

		/*!	\brief	Return true if a type has an ostream operator(<<) */
		template<typename T>
		bool isPrintable(const T&){
			return Check::has_ostream_operator<T>::value;
		}

		/*!	\brief	A function that say if a type has an ostream operator(<<) */
		template<typename T>
		void printable(const T& in){
			std::string type = __PRETTY_FUNCTION__;

			auto pos = type.find(" = ");
			if(pos != std::string::npos){
				type.erase(0, pos+3);
			}

			pos = type.find("]");
			if(pos != std::string::npos){
				type.erase(type.begin()+pos, type.end());
			}

			std::vector<std::pair<std::string, std::string>> replaces;

			replaces.push_back({"> >", ">>"});
			replaces.push_back({"std::__cxx11::basic_string<char>", "std::string"});

			for(auto& r : replaces){
				do {
					pos = type.find(r.first);
					if(pos != std::string::npos){
						type.replace(pos, r.first.size(), r.second);
					}
				} while(pos != std::string::npos);
			}

			std::cout << "Is " << type << " printable ? " << std::boolalpha << isPrintable(in) << std::endl;
		}

		/*! \brief	A template class to test if T is an unknown object */
		template<typename T>
		class is_object {
			public:
				const static bool value = !is_array<T>::value &&
										  !is_string<T>::value &&
										  !is_smatch<T>::value &&
										  !std::is_fundamental<T>::value;
		};

		/*! \brief	A template class to test if T is a special struct */
		template<typename T>
		class is_special_struct {
			public:
				const static bool value = is_pair<T>::value ||
										  is_trio<T>::value ||
										  is_quatuor<T>::value;
		};

		#ifndef DOXYGEN_SHOULD_SKIP_THIS
		
		#endif //DOXYGEN_SHOULD_SKIP_THIS
	}
}

#endif //HEADER_CPP_CHECK)
