/*!
*
*	\file		cryptage.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\modified	September, 24 2019
*
*/
#ifndef HEADER_CPP_CRYPTAGE
#define HEADER_CPP_CRYPTAGE

#include "C++/defines.hpp"

namespace mcd {
	/*!
	* \class	Crypto
	* \brief	A class to be the parent for every crypt class
	*/
	class Crypto : public NotCopyable {
		public:
			/* Constructor & Destructor */
			Crypto();
			virtual ~Crypto(){}

			/* Getters */

			/* Setters */

			/* Others */
			/*!
			* \details		Pur virtual function to disallow you to use the class alone
			*		\param[in]	message			The message to crypt
			*		\return		void
			*/
			virtual std::string crypt(const std::string& message) = 0;
			/*!
			* \details		Pur virtual function to disallow you to use the class alone
			*		\param[in]	message			The message to decrypt
			*		\return		void
			*/
			virtual std::string decrypt(const std::string& message) = 0;
	};

	/*!
	* \class	Cesar
	* \brief	A class to use the cesar algorithm for encryption
	*/
	class Cesar : public Crypto {
		public:
			/* Constructor & Destructor */
			Cesar(){}
			virtual ~Cesar(){}

			/* Getters */

			/* Setters */

			/* Others */
			/*!
			* \brief	Overload of the crypt Crypto's method
			*		\param[in]		message		The message to encrypt
			*		\param[in]		decal		The shift to crypt the message
			*
			*		\return			Return the crypted message
			*/
			std::string crypt(const std::string& message, int decal);
			/*!
			* \brief	Overload of the decrypt Crypto's method
			*		\param[in]		message		The message to decrypt
			*		\param[in]		decal		The shift to decrypt the message
			*
			*		\return			Return the decrypted message
			*/
			std::string decrypt(const std::string& message, int decal);
			/*!
			* \brief	Overload of the decrypt Crypto's method in brut force
			*		\param[in]		message		The message to decrypt
			*
			*		\return			Return the decrypted message
			*/
			virtual std::string decrypt(const std::string& message) override;

		private:
			virtual std::string crypt(const std::string&) override { return ""; }
	};

	#ifndef DOXYGEN_SHOULD_SKIP_THIS
		#define SHA2_SHFR(x, n)	(x >> n)
		#define SHA2_ROTR(x, n)   ((x >> n) | (x << ((sizeof(x) << 3) - n)))
		#define SHA2_CH(x, y, z)  ((x & y) ^ (~x & z))
		#define SHA2_MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))

		#define SHA256_F1(x) (SHA2_ROTR(x,  2) ^ SHA2_ROTR(x, 13) ^ SHA2_ROTR(x, 22))
		#define SHA256_F2(x) (SHA2_ROTR(x,  6) ^ SHA2_ROTR(x, 11) ^ SHA2_ROTR(x, 25))
		#define SHA256_F3(x) (SHA2_ROTR(x,  7) ^ SHA2_ROTR(x, 18) ^ SHA2_SHFR(x,  3))
		#define SHA256_F4(x) (SHA2_ROTR(x, 17) ^ SHA2_ROTR(x, 19) ^ SHA2_SHFR(x, 10))

		#define SHA2_UNPACK32(x, str)							\
		{														\
			*((str) + 3) = static_cast<uint8_t>((x));			\
			*((str) + 2) = static_cast<uint8_t>((x) >> 8);		\
			*((str) + 1) = static_cast<uint8_t>((x) >> 16);		\
			*((str) + 0) = static_cast<uint8_t>((x) >> 24);		\
		}

		#define SHA2_PACK32(str, x)									\
		{															\
			*(x) = (static_cast<uint32_t>(*((str) + 3)))			\
				 | (static_cast<uint32_t>(*((str) + 2)) << 8)		\
				 | (static_cast<uint32_t>(*((str) + 1)) << 16)		\
				 | (static_cast<uint32_t>(*((str) + 0)) << 24);		\
		}
	#endif //DOXYGEN_SHOULD_SKIP_THIS

	/*!
	* \class	SHA2
	* \brief	An implementation of sha256 encryption
	*/
	class SHA2 : public Crypto {
		public:
			/* Constructor & Destructor */
			SHA2();
			virtual ~SHA2(){}

			/* Getters */

			/* Setters */

			/* Others */
				/*!
				* \brief	Overload of the crypt Crypto's method
				*		\param[in]		message		The message to encrypt
				*
				*		\return			Return the crypted message
				*/
				virtual std::string crypt(const std::string& message) override;

		protected:
			/*!
			* \brief	Transform the message in the block number
			*		\param[in]		message		The message to encrypt
			*		\param[in]		block_nb	The number of the block to encrypt
			*
			*		\return			void
			*/
			void transform(const uint8_t* message, size_t block_nb);
			/*!
			* \brief	Update the message
			*		\param[in]		message		The message to encrypt
			*
			*		\return			void
			*/
			void update(const std::string& message);
			/*!
			* \brief	The final update of the message
			*		\param[in]		digest		The different part of the message
			*
			*		\return			void
			*/
			void final(uint8_t* digest);

		private:
			virtual std::string decrypt(const std::string&) override { return ""; }

		protected:
			const static size_t DIGEST_SIZE = (256/8);
			const static uint32_t sha2_keys[];
			const static size_t BLOCK_SIZE = (512/8);

			size_t totalLength;
			size_t length;
			uint8_t block[2*BLOCK_SIZE];
			uint32_t h[8];
	};

	/*!
	* \class	MyCrypt
	* \brief	A class to test a homemade algorithm for encryption
	*/
	class MyCrypt : public Crypto {
		public:
			MyCrypt() :
				Crypto(),
				_str_key("")
			{}
			~MyCrypt(){}
			/* Others */
				/*!
				* \brief	Crypt the message with a pass key
				*		\param[in]		str			The message to encrypt
				*		\param[in]		key			The key to use
				*
				*		\return			Return the encrypted message
				*/
				virtual std::string crypt(const std::string& str, const std::string& key);
				/*!
				* \brief	Decrypt the message with a pass key
				*		\param[in]		str			The message to decrypt
				*		\param[in]		key			The key to use
				*
				*		\return			Return the decrypted message
				*/
				virtual std::string decrypt(const std::string& str, const std::string& key);
				/*!
				* \brief	Overload of the crypt Crypto's method
				*		\param[in]		str			The message to encrypt
				*
				*		\return			Return the encrypted message
				*/
				virtual std::string crypt(const std::string& str) override;
				/*!
				* \brief	Overload of the decrypt Crypto's method
				*		\param[in]		str			The message to decrypt
				*
				*		\return			Return the decrypted message
				*/
				virtual std::string decrypt(const std::string& str) override;
		private:
			std::string _str_key;
	};

	/*!
	* \class	RSA
	* \brief	A class to use the RSA algorithm for encryption
	* \todo		Create the class
	*/
	class RSA : public Crypto {
		public:
			/* Constructor & Destructor */
			RSA();
			virtual ~RSA(){}

			/* Getters */
			/*!
			* \brief	Get the public key
			*		\return			Return the public key of the object
			*/
			std::string getPublic()const;
			/*!
			* \brief	Get the private key
			*		\return			Return the private key of the object
			*/
			std::string getPrivate()const;

			/* Setters */
			/*!
			* \brief	Set the public key
			*		\param[in]		key			The key
			*
			*		\return			void
			*/
			void setPublic(const std::string& key="");
			/*!
			* \brief	Set the private key
			*		\param[in]		key			The key
			*
			*		\return			void
			*/
			void setPrivate(const std::string& key="");

			/* Others */
			/*!
			* \brief	Overload of the crypt Crypto's method
			*		\param[in]		message			The message to encrypt
			*
			*		\return			Return the encrypted message
			*/
			virtual std::string crypt(const std::string& message) override;
			/*!
			* \brief	Overload of the decrypt Crypto's method
			*		\param[in]		message			The message to decrypt
			*
			*		\return			Return the decrypted message
			*/
			virtual std::string decrypt(const std::string& message) override;
		protected:
			std::string publicK;
			std::string privateK;
	};

	/*! \brief	A global cesar variable to crypt and decrypt messages */
	extern Cesar cesar;

	/*! \brief	A global sha2 variable to crypt messages */
	extern SHA2 sha2;

	/*! \brief	A global MyCrypt variable to crypt messages */
	extern MyCrypt mycrypt;
}

#endif //HEADER_CPP_CRYPTAGE
