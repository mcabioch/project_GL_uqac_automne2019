namespace mcd {
	/*! \brief	The Big PI constant */
	#define BIG_PI "3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798"
	/*! \brief	The Big Euler constant */
	#define BIG_E "2.7182818284590452353602874713526624977572470936999595749669676277240766303535475945713821785251664274"

	/*!
	* \brief	Compute the square of \a a
	*	\param[in]		a			The value to use
	*	\return			Return the square of \a a
	*/
	inline Big sq(const Big& a){
		return pow(a, Big(2));
	}

	/*!
	* \brief	Compute the squareroot of \a a
	*	\param[in]		a			The value to use
	*	\return			Return the squareroot of \a a
	*/
	inline Big sqrt(const Big& a){
		return nroot(a, 2);
	}

	/*!
	* \brief	Compute the ppcm
	*	\param[in]		a			The value to use
	*	\param[in]		b			The value to use
	*	\return			Return the ppcm of \a a and \a b
	*/
	inline Big ppcm(const Big& a, const Big& b){
		return (a * b) / pgcd(a, b);
	}

	/*!
	* \brief	Return \b true if \a a / \a b = 0
	*	\param[in]		a			The value to use
	*	\param[in]		b			The value to use
	*	\return			Return \b true or \b false
	*/
	inline bool isDivisor(const Big& a, const Big& b) {
		return ((a % b) == Big(0));
	}

	/*!
	* \brief	Compute the absolute value of \a a
	*	\param[in]		a			The value to use
	*	\return			Return the absolute value of \a a
	*/
	inline Big abs(const Big& a){
		return (a < Big(0))?(a * Big(-1)):a;
	}

	#if 0
		/*!
		* \brief	
		*	\param[in]		a			
		*	\return			
		*/
		Big ln(const Big& a);

		/*!
		* \brief	
		*	\param[in]		a			
		*	\return			
		*/
		Big log(const Big& a);

		/*!
		* \brief	
		*	\param[in]		a			
		*	\return			
		*/
		Big exp(const Big& a){
			return pow(BIG_E, a);
		}

		/*!
		* \brief	
		*	\param[in]		a			
		*	\return			
		*/
		Big sin(const Big& a);

		/*!
		* \brief	
		*	\param[in]		a			
		*	\return			
		*/
		Big cos(const Big& a);

		/*!
		* \brief	
		*	\param[in]		a			
		*	\return			
		*/
		Big tan(const Big& a);

		/*!
		* \brief	
		*	\param[in]		a			
		*	\return			
		*/
		Big fact(const Big& a);
	#endif
}
