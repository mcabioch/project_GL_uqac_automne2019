namespace mcd {
	/*! \brief	Construct a Big with any type */
	template<typename T, class = std::enable_if_t<std::is_arithmetic<T>::value> >
	Big::Big(T val) :
		Big(toBigVal(val))
	{}
}
