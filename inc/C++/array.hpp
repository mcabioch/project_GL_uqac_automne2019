/*!
*
*	\file		array.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	October, 03 2019
*
*/
#ifndef HEADER_CPP_ARRAY
#define HEADER_CPP_ARRAY

#include <stdexcept>

#include "C++/check.hpp"
#include "C++/sorting.hpp"

namespace mcd {
	/*!
	* \brief	Stick the \a a vector with the \a glue given
	*		\param[in]		a			The array to stick
	*		\param[in]		glue		The string to stick the array's elements
	*
	*		\return			Return a string of the array
	*/
	template<typename T>
	std::string implode(const std::vector<T>& a, const std::string& glue = ""){
		std::string out{""};
		size_t size = a.size();
		size_t index = 0;

		for(auto& elem : a){
			std::stringstream tmp;
			tmp << elem;

			out += tmp.str();

			if(index+1 < size){
				out += glue;
			}

			index ++;
		}

		return out;
	}

	#ifdef DOXYGEN_SHOULD_SKIP_THIS
		/*!
		* \brief	Print the content of an array
		*		\param[in]		a		The array to print
		*
		*		\return			void
		*/
		template<typename Array>
		void print_r(const Array& a);
	#else
		/*!
		* \brief	Print the content of a vector
		*		\param[in]		a		The vector to print
		*
		*		\return			void
		*/
		template<typename T>
		void print_r(const std::vector<T>& a){
			size_t index{0};
			for(auto& elem : a){
				std::cout << index << " : '" << elem << "'" << std::endl;
				index++;
			}
		}

		/*!
		* \brief	Print the content of an array
		*		\param[in]		a		The array to print
		*
		*		\return			void
		*/
		template<typename T>
		typename std::enable_if_t<std::is_array<T>::value && !Check::is_printable<T>::value>
		print_r(const T& a){
			size_t index{0};

			for(auto& elem : a){
				std::cout << index << " : '" << elem << "'" << std::endl;
				index++;
			}
		}
	#endif //DOXYGEN_SHOULD_SKIP_THIS

	/*!
	* \brief	Rewrite a vector array without the value at the given index
	*		\param[in]		table		The array to rewrite
	*		\param[in]		index		The index not to let in the array
	*
	*		\return			Return an array without the \a index
	*/
	template<typename V>
	std::vector<V> rewrite(const std::vector<V>& table, unsigned index) {
		std::vector<V> out;

		for(unsigned i{0}; i < index; ++i){
			out.push_back(table[i]);
		}
		for(unsigned i{index+1}; i < table.size(); ++i){
			out.push_back(table[i]);
		}

		return out;
	}

	/*!
	* \brief	Verify if a vector contains or not something
	*		\param[in]		table		The array in which to verify
	*		\param[in]		value		The value to search
	*
	*		\return			\b true or \b false
	*/
	template<typename T>
	bool contains(const std::vector<T>& table, T value){
		/*std::cout << "Contains ;" << std::endl;
		std::cout << "\t- value : '" << value << "'" << std::endl;
		std::cout << "\t- table.size() = " << table.size() << std::endl;
		std::cout << "\t- table ;" << std::endl;
		for(size_t i{0}; i < table.size(); ++i){
			std::cout << "\t\t- table[" << i << "] = '" << table[i] << "'" << std::endl;
		}*/

		if(table.empty()){ return false; }

		if(std::find(table.begin(), table.end(), value) == table.end()){ return false; }

		return true;
	}

	#ifdef DOXYGEN_SHOULD_SKIP_THIS
		/*!
		* \brief	Prints approximately everything
		*		\param[in]		data		The data to print
		*		\param[in]		change		\b true or \b false, \b true to print the value of a pointer instead of his address
		*/
		template<typename Something>
		void print_all(const Something& data, bool change = false);
	#else
		/* print_all function */
			template<typename T>
			typename std::enable_if_t<
									Check::is_object<T>::value &&
									!Check::is_special_struct<T>::value &&
									!Check::is_printable<T>::value &&
									!Check::is_minded_ptr<T>::value
									>
			print_all(const T&, bool = false, const std::string& decal = "");

			template<typename T>
			typename std::enable_if_t<
									Check::is_object<T>::value &&
									!Check::is_printable<T>::value &&
									!Check::is_minded_ptr<T>::value
									>
			print_all(T* data, bool change = false, const std::string& decal = "");

			template<typename T>
			typename std::enable_if_t<
									Check::is_object<T>::value &&
									Check::is_printable<T>::value &&
									Check::is_minded_ptr<T>::value
									>
			print_all(const T& data, bool change = false, const std::string& decal = "");

			template<typename T>
			typename std::enable_if_t<
									(
										std::is_fundamental<T>::value ||
										Check::is_string<T>::value
									) &&
									Check::is_printable<T>::value &&
									!Check::is_minded_ptr<T>::value
									>
			print_all(const T& data, bool = false, const std::string& decal = "");

			template<typename T>
			typename std::enable_if_t<
									!std::is_fundamental<T>::value &&
									!Check::is_string<T>::value &&
									Check::is_printable<T>::value &&
									!Check::is_minded_ptr<T>::value
									>
			print_all(const T& data, bool = false, const std::string& decal = "");

			void print_all(const std::smatch& data, bool change = false, const std::string& decal = "");

			template<typename T>
			typename std::enable_if_t<
									Check::is_array<T>::value
									>
			print_all(T* data, bool change = false, const std::string& decal = "");

			template<typename T>
			typename std::enable_if_t<
									Check::is_array<T>::value &&
									!Check::is_vector<T>::value
									>
			print_all(const T& data, bool change = false, const std::string& decal = "");

			template<typename T>
			void print_all(const std::vector<T>& data, bool change = false, const std::string& decal = "");

			template<typename T>
			void print_all(const vector<T>& data, bool change = false, const std::string& decal = "");

			template<typename T, typename U>
			void print_all(const std::pair<T, U>& data, bool change = false, const std::string& decal = "");

			template<typename T, typename U, typename V>
			void print_all(const trio<T, U, V>& data, bool change = false, const std::string& decal = "");

			template<typename T, typename U, typename V, typename W>
			void print_all(const quatuor<T, U, V, W>& data, bool change = false, const std::string& decal = "");

			/* End */
				template<typename T>
				typename std::enable_if_t<
										Check::is_object<T>::value &&
										!Check::is_special_struct<T>::value &&
										!Check::is_printable<T>::value &&
										!Check::is_minded_ptr<T>::value
										>
				print_all(const T&, bool, const std::string& decal){
					std::cout << decal << "Object" << std::endl;
				}

				template<typename T>
				typename std::enable_if_t<
										Check::is_object<T>::value &&
										!Check::is_printable<T>::value &&
										!Check::is_minded_ptr<T>::value
										>
				print_all(T* data, bool change, const std::string& decal){
					if(change){
						std::cout << decal << "(" << data << ")" << std::endl;
					} else {
						print_all(*data, change, decal);
					}
				}

				template<typename T>
				typename std::enable_if_t<
										Check::is_object<T>::value &&
										Check::is_printable<T>::value &&
										Check::is_minded_ptr<T>::value
										>
				print_all(const T& data, bool change, const std::string& decal){
					if(change){
						std::cout << decal << "(" << data << ")" << std::endl;
					} else {
						print_all(*data, change, decal);
					}
				}

				template<typename T>
				typename std::enable_if_t<
										(
											std::is_fundamental<T>::value ||
											Check::is_string<T>::value
										) &&
										Check::is_printable<T>::value &&
										!Check::is_minded_ptr<T>::value
										>
				print_all(const T& data, bool, const std::string& decal){
					std::cout << decal << "'" << data << "'" << std::endl;
				}

				template<typename T>
				typename std::enable_if_t<
										!std::is_fundamental<T>::value &&
										!Check::is_string<T>::value &&
										Check::is_printable<T>::value &&
										!Check::is_minded_ptr<T>::value
										>
				print_all(const T& data, bool, const std::string& decal){
					std::cout << decal << data << std::endl;
				}
			/*******/

			template<typename T, typename U>
			void print_all(const std::pair<T, U>& data, bool change, const std::string& decal){
				std::cout << decal << "pair" << std::endl;
				print_all(data.first, change, decal + "--");
				print_all(data.second, change, decal + "--");
			}

			template<typename T, typename U, typename V>
			void print_all(const trio<T, U, V>& data, bool change, const std::string& decal){
				std::cout << decal << "trio" << std::endl;
				print_all(data.first, change, decal + "--");
				print_all(data.second, change, decal + "--");
				print_all(data.ter, change, decal + "--");
			}

			template<typename T, typename U, typename V, typename W>
			void print_all(const quatuor<T, U, V, W>& data, bool change, const std::string& decal){
				std::cout << decal << "quatuor" << std::endl;
				print_all(data.first, change, decal + "--");
				print_all(data.second, change, decal + "--");
				print_all(data.ter, change, decal + "--");
				print_all(data.quad, change, decal + "--");
			}

			template<typename T>
			typename std::enable_if_t<
									Check::is_array<T>::value
									>
			print_all(T* data, bool change, const std::string& decal){
				if(change){
					std::cout << decal << "(" << data << ")[" << data->size() << "]" << std::endl;
				} else {
					print_all(*data, change, decal);
				}
			}

			template<typename T>
			typename std::enable_if_t<
									Check::is_array<T>::value &&
									!Check::is_vector<T>::value
									>
			print_all(const T& data, bool change, const std::string& decal){
				std::cout << decal << "array[" << data.size() << "]" << std::endl;
				size_t i{0};
				for(auto d : data){
					print_all(d, change, decal + "--");
					++i;
				}
			}

			template<typename T>
			void print_all(const std::vector<T>& data, bool change, const std::string& decal){
				std::cout << decal << "vector[" << data.size() << "]" << std::endl;
				size_t i{0};
				for(auto d : data){

					std::string size = "[" + std::to_string(i) + "] :";
					std::string addDecal = "";

					for(size_t j{0}; j < size.size(); ++j){
						addDecal += " ";
					}

					std::cout << decal << size << std::endl;

					print_all(d, change, decal + addDecal);
					++i;
				}
			}

			template<typename T>
			void print_all(const vector<T>& data, bool change, const std::string& decal){
				print_all(static_cast<std::vector<T>>(data), change, decal);
			}
		/**********************/
	#endif //DOXYGEN_SHOULD_SKIP_THIS

	/*
	* \brief	Convert 2D coords to 1D coords
	*		\param		x			The x coord
	*		\param		y			The y coord
	*		\param		maxX		The maximum length of a line
	*		\return		Return the 1D coord
	*/
	inline size_t array2Dto1D(size_t x, size_t y, size_t maxX){
		return y * maxX + x;
	}
	/*
	* \brief	Convert 1D coords to 2D coords
	*		\param		index			The 1D coord
	*		\param		maxX			The maximum length of a line
	*		\return		Return a std::pair containing the 2D coords
	*/
	inline std::pair<size_t, size_t> array1Dto2D(size_t index, size_t maxX){
		return std::make_pair(index % maxX, index / maxX);
	}

	/*
	* \brief	Convert 2D coords to 1D coords
	*		\param		pt			The coords
	*		\param		maxX		The maximum length of a line
	*		\return		Return the 1D coord
	*/
	inline size_t array2Dto1D(const Point& pt, size_t maxX){
		return array2Dto1D(static_cast<size_t>(pt.x), static_cast<size_t>(pt.y), maxX);
	}

	/*!
	* \class	stack
	* \brief	An implementation of std::stack
	*/
	template<class T, class Container = std::deque<T>>
	class stack : public std::stack<T, Container> {
		public:
			/* Constructor */
			stack() :
				std::stack<T, Container>()
			{}

			/* Getters */
				/*! \brief	Return the first element of the stack and erase it from the stack */
				T get(){
					T el = this->top();
					this->pop();
					return el;
				}
	};

	/*!
	* \class	t_stack
	* \brief	An thread-safe implementation of stack
	*/
	template<class T, class Container = std::deque<T>>
	class t_stack : public stack<T, Container> {
		public:
			/* Constructor */
			t_stack() :
				stack<T, Container>(),
				_mutex()
			{}

			MUTEX_CONST_RECREATE(stack<T COMMA Container>, top, T&)
			MUTEX_CONST_RECREATE(stack<T COMMA Container>, empty, bool)
			MUTEX_CONST_RECREATE(stack<T COMMA Container>, size, size_t)
			MUTEX_VOID_RECREATE(stack<T COMMA Container>, pop)

			void push(const T& value){
				_mutex.lock();
				stack<T, Container>::push(value);
				_mutex.unlock();
			}

			void push(T&& value){
				_mutex.lock();
				stack<T, Container>::push(value);
				_mutex.unlock();
			}

		private:
			mutable mutex _mutex;
	};

	/*!
	* \class	queue
	* \brief	An implementation of std::queue
	*/
	template<class T, class Container = std::deque<T>>
	class queue : public std::queue<T, Container> {
		public:
			/* Constructor */
			queue() :
				std::queue<T, Container>()
			{}

			/* Getters */
				/*! \brief	Erase the first element of the queue */
				void pop(){
					if(!this->empty()){
						std::queue<T, Container>::pop();
					}
				}

				/*! \brief	Return the first element of the queue and erase it from the queue */
				T get(){
					T el = this->front();
					this->pop();
					return el;
				}
	};

	/*!
	* \class	t_queue
	* \brief	An thread-safe implementation of queue
	*/
	template<class T, class Container = std::deque<T>>
	class t_queue : public queue<T, Container> {
		public:
			/* Constructor */
			t_queue() :
				queue<T, Container>(),
				_mutex()
			{}

			MUTEX_CONST_RECREATE(queue<T COMMA Container>, front, T&)
			MUTEX_CONST_RECREATE(queue<T COMMA Container>, back, T&)
			MUTEX_CONST_RECREATE(queue<T COMMA Container>, empty, bool)
			MUTEX_CONST_RECREATE(queue<T COMMA Container>, size, size_t)
			MUTEX_VOID_RECREATE(queue<T COMMA Container>, pop)

			void push(const T& value){
				_mutex.lock();
				queue<T, Container>::push(value);
				_mutex.unlock();
			}

			void push(T&& value){
				_mutex.lock();
				queue<T, Container>::push(value);
				_mutex.unlock();
			}


		private:
			mutable mutex _mutex;
	};
}

#endif //HEADER_CPP_ARRAY
