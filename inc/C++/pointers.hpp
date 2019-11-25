/*!
*
*	\file		pointers.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	October, 03 2019
*
*/
#ifndef HEADER_CPP_POINTERS
#define HEADER_CPP_POINTERS

#include "C++/types.hpp"

#ifndef OS_WINDOWS
	#include <thread>
	#include <mutex>

	namespace mcd {
		using thread = std::thread;
		using mutex = std::mutex;
	}
#else
	#include "boost/thread.hpp"

	namespace mcd {
		using thread = boost::thread;
		using mutex = boost::mutex;
	}
#endif

#define MUTEX_RECREATE(parent, name, type) \
type name(){\
	_mutex.lock();\
	type out = parent::name();\
	_mutex.unlock();\
	return out;\
}

#define MUTEX_RECREATE_ARGS(parent, name, type, ...) \
type name(__VA_ARGS__){\
	_mutex.lock();\
	type out = parent::name(__VA_ARGS__);\
	_mutex.unlock();\
	return out;\
}

#define MUTEX_VOID_RECREATE(parent, name) \
void name(){\
	_mutex.lock();\
	parent::name();\
	_mutex.unlock();\
}

#define MUTEX_VOID_RECREATE_ARGS(parent, name, ...) \
void name(__VA_ARGS__){\
	_mutex.lock();\
	parent::name(__VA_ARGS__);\
	_mutex.unlock();\
}

#define MUTEX_CONST_RECREATE(parent, name, type) \
type name() const {\
	_mutex.lock();\
	type out = parent::name();\
	_mutex.unlock();\
	return out;\
}

#define MUTEX_CONST_RECREATE_ARGS(parent, name, type, ...) \
type name(__VA_ARGS__) const {\
	_mutex.lock();\
	type out = parent::name(__VA_ARGS__);\
	_mutex.unlock();\
	return out;\
}

#define MUTEX_VOID_CONST_RECREATE(parent, name) \
void name() const {\
	_mutex.lock();\
	parent::name();\
	_mutex.unlock();\
}

#define MUTEX_VOID_CONST_RECREATE_ARGS(parent, name, ...) \
void name(__VA_ARGS__) const {\
	_mutex.lock();\
	parent::name(__VA_ARGS__);\
	_mutex.unlock();\
}

namespace mcd {
	namespace Check {
		/*! \brief	A template class to test if T is a std::shared_ptr, a std::unique_ptr or a std::weak_ptr */
		template<typename T>
		class is_minded_ptr{
			public:
				const static bool value = false;
		};

		#ifndef DOXYGEN_SHOULD_SKIP_THIS
			template<typename T>
			class is_minded_ptr<std::shared_ptr<T>>{
				public:
					const static bool value = true;
			};
			template<typename T>
			class is_minded_ptr<std::unique_ptr<T>>{
				public:
					const static bool value = true;
			};
			template<typename T>
			class is_minded_ptr<std::weak_ptr<T>>{
				public:
					const static bool value = true;
			};
		#endif //DOXYGEN_SHOULD_SKIP_THIS

		/*! \brief	A template class to test if T is a std::shared_ptr<thread>, a std::unique_ptr<thread>, a std::weak_ptr<thread> or a thread* */
		template<typename T>
		class is_thread_ptr{
			public:
				const static bool value = false;
		};

		#ifndef DOXYGEN_SHOULD_SKIP_THIS
			template<>
			class is_thread_ptr<std::shared_ptr<thread>>{
				public:
					const static bool value = true;
			};
			template<>
			class is_thread_ptr<std::unique_ptr<thread>>{
				public:
					const static bool value = true;
			};
			template<>
			class is_thread_ptr<std::weak_ptr<thread>>{
				public:
					const static bool value = true;
			};
			template<>
			class is_thread_ptr<thread*>{
				public:
					const static bool value = true;
			};
		#endif //DOXYGEN_SHOULD_SKIP_THIS
	}

	#ifndef DOXYGEN_SHOULD_SKIP_THIS
	template<typename T>
	typename std::enable_if_t<Check::is_thread_ptr<T>::value>
	deleteThreadPtr(T& pointer){
		try {
			if(pointer->joinable()){
				pointer->join();
			}
		} catch(std::system_error& e){}
	}

	template<typename T>
	typename std::enable_if_t<!Check::is_thread_ptr<T>::value>
	deleteThreadPtr(T&){}
	#endif /* DOXYGEN_SHOULD_SKIP_THIS */


	#ifndef DOXYGEN_SHOULD_SKIP_THIS
	template<typename T>
	typename std::enable_if_t<Check::is_minded_ptr<T>::value>
	deleteResetPtr(T& pointer){
		pointer = nullptr;
	}
	#endif /* DOXYGEN_SHOULD_SKIP_THIS */
	#ifndef DOXYGEN_SHOULD_SKIP_THIS
	template<typename T>
	typename std::enable_if_t<!Check::is_minded_ptr<T>::value>
	deleteResetPtr(T& pointer){
		delete pointer;
		pointer = nullptr;
	}
	#endif /* DOXYGEN_SHOULD_SKIP_THIS */

	/*!
	* \brief	Delete a pointer
	*		\param[in,out]		pointer		The pointer to delete
	*
	*		\return			void
	* \details	Delete \a pointer if is \b not \b equal to nullptr and \b not a joinable thread pointer.\n
	* 			For a joinable thread pointer, it wait for the end of the function.\n
	* 			After delete, it put the pointer to \b nullptr.
	*/
	template<typename T>
	typename std::enable_if_t<std::is_pointer<T>::value || Check::is_minded_ptr<T>::value>
	deletePtr(T& pointer){
		if(pointer == nullptr){
			return;
		}
		if(Check::is_thread_ptr<T>::value){
			deleteThreadPtr(pointer);
		}

		deleteResetPtr(pointer);
	}
}

#endif //HEADER_CPP_POINTERS
