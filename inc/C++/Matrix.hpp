/*!
*
*	\file		Matrix.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Sunday September, 15 2019 19:17:03
*	\modified	September, 26 2019
*
*/
#ifndef HEADER_MATRIX
#define HEADER_MATRIX

#include "C++/Fraction.hpp"

namespace mcd {
	/*!
	* \class	Matrix
	* \brief	A class to represent matrix
	*/
	template<class C>
	class Matrix {
		/* Usefull or required defines */
			
		/* Members of Matrix */
		public:
			/* Internal enums of Matrix */
				
			/* Constructors & Destructor of Matrix */
				/*! \brief	The constructor of the class */
				Matrix();
				explicit Matrix(const std::vector<std::vector<C>>& datas);
				template<std::size_t M, std::size_t N>
				explicit Matrix(std::array<std::array<C, M>, N>& datas);
				virtual ~Matrix(){}
			/* Getters of Matrix */
				size_t i()const { return _i; }
				size_t j()const { return _j; }
				bool isSquare()const { return _square; }

				Matrix<C> getIdentity();
			/* Setters of Matrix */
				
			/* Statics of Matrix */
				
			/* Operators of Matrix */
				/*!
				* \brief	operator() to get a value in the matrix
				*	\param[in]		i		A matrix place
				*	\param[in]		j		A matrix place
				*	\return					The corresponding value
				*/
				C operator()(size_t i, size_t j)const {
					if(i == 0 || i > _i || j == 0 || j > _j){
						throw std::string("Matrix::operator() : Wrong boundaries !");
					}

					return _datas[i-1][j-1];
				}
				/*!
				* \brief	operator() to get a value in the matrix
				*	\param[in]		i		A matrix place
				*	\param[in]		j		A matrix place
				*	\return					A reference to the corresponding value
				*/
				C& operator()(size_t i, size_t j) {
					if(i == 0 || i > _i || j == 0 || j > _j){
						throw std::string("Matrix::operator() : Wrong boundaries !");
					}

					return _datas[i-1][j-1];
				}

				template<class D>
				Matrix<C>& operator+=(const Matrix<D>& A);
				template<class D>
				Matrix<C> operator+(const Matrix<D>& A);

				Matrix<C> operator-();

				template<class D>
				Matrix<C>& operator-=(const Matrix<D>& A);
				template<class D>
				Matrix<C> operator-(const Matrix<D>& A);

				template<class D>
				Matrix<C>& operator*=(const D& a);
				template<class D>
				Matrix<C> operator*(const D& a);

				template<class D>
				Matrix<C>& operator*=(const Matrix<D>& A);
				template<class D>
				Matrix<C> operator*(const Matrix<D>& A);

				template<class D>
				Matrix<C>& operator/=(const D& a);
				template<class D>
				Matrix<C> operator/(const D& a);
			/* Friends of Matrix */
				/*!
				* \brief	Implementation of the Gauss-Jordan algorithm
				*	\param[in]			M		The matrix to invert
				*	\param[in,out]		I		The matrix' identity
				*	\param[in]			i		A matrix place
				*	\param[in]			j		A matrix place
				*	\return						void
				*/
				template<class D>
				friend void GaussJordan(const Matrix<D>& M, Matrix<D>& I, size_t i, size_t j);

				template<class D>
				friend std::ostream& operator<<(std::ostream& os, const Matrix<D>& M);
			/* Others members of Matrix */
				/*!
				* \brief	Transpose the matrix
				*	\return			The transposed matrix
				*/
				Matrix<C> transposed();
				/*!
				* \brief	Compute the determinant of the matrix
				*	\return			The value of the determinant
				*/
				double det();
				/*!
				* \brief	Invert the matrix using Gaus-Jordan algorithm
				*	\return			The inverted matrix
				*/
				Matrix<C> inverted();

		protected:
			/* Getters of Matrix */
				bool enabled()const { return _enabled; }
			/* Setters of Matrix */
				
			/* Statics of Matrix */
				
			/* Friends of Matrix */
				
			/* Others members of Matrix */
				

		private:
			void init(const std::vector<std::vector<C>>& datas);
			void init_vect(size_t i, size_t j, C default_value = 0);

			void test_square();

			Matrix<C> mineur(size_t i, size_t j);

			template<class T>
			static std::string tos(T value);

		/* Atttributes of Matrix */
		public:
			/* Global */
				
			/* Local */
				

		protected:
			/* Global */
				
			/* Local */
				

		private:
			/* Global */
				
			/* Local */
				bool _enabled;
				bool _square;

				std::vector<std::vector<C>> _datas;
				size_t _i, _j;
	};

	#ifndef DOXYGEN_SHOULD_SKIP_THIS
		#include "Matrix_constructs.hpp"
		#include "Matrix_maths.hpp"
		#include "Matrix_core.hpp"
	#endif //DOXYGEN_SHOULD_SKIP_THIS

	#ifndef DOXYGEN_SHOULD_SKIP_THIS
		#include "Matrix_functions.hpp"
	#endif //DOXYGEN_SHOULD_SKIP_THIS
}

#endif //HEADER_MATRIX
