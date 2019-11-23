namespace mcd {
	template<typename T, class = std::enable_if_t<std::is_arithmetic<T>::value> >
	Big::operator T()const noexcept {
		T out = 0;

		for(size_t i = 0; i < _val.size(); ++i){
			out += static_cast<T>(_val[i]) * static_cast<T>(pow(10, static_cast<double>(i)));
		}

		return out;
	}

	/*! \brief	++Big */
	inline Big operator++(Big& in, int) noexcept {
		Big tmp = in;
		in += Big(1);
		return tmp;
	}

	/*! \brief	Big++ */
	inline Big& operator++(Big& in) noexcept {
		in += Big(1);
		return in;
	}

	/*! \brief	--Big */
	inline Big operator--(Big& in, int) noexcept {
		Big tmp = in;
		in -= Big(1);
		return tmp;
	}

	/*! \brief	Big-- */
	inline Big& operator--(Big& in) noexcept {
		in -= Big(1);
		return in;
	}

	/*! \brief	+Big */
	inline Big operator+(const Big& in) noexcept {
		return in;
	}

	/*! \brief	-Big */
	inline Big operator-(const Big& in) noexcept {
		return in.invert();
	}
}
