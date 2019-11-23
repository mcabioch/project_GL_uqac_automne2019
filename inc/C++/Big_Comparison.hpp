namespace mcd {
	/*! \brief	Compare two Big */
	inline bool operator==(const Big& a, const Big& b) noexcept{
		return (a._val == b._val) && (a._neg == b._neg);
	}

	/*! \brief	Compare two Big */
	inline bool operator<(const Big& a, const Big& b) noexcept{
		return (a != b) && !(a > b);
	}

	/*! \brief	Compare two Big */
	inline bool operator!=(const Big& a, const Big& b) noexcept {
		return !(a == b);
	}

	/*! \brief	Compare two Big */
	inline bool operator<=(const Big& a, const Big& b) noexcept {
		return (a < b) || (a == b);
	}

	/*! \brief	Compare two Big */
	inline bool operator>=(const Big& a, const Big& b) noexcept {
		return (a > b) || (a == b);
	}
}
