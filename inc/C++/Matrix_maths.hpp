/*!
*
*	\file		Matrix_maths.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Sunday September, 15 2019 19:17:03
*	\modified	Sunday September, 16 2019
*
*/
#ifndef HEADER_MATRIX_MATHS
#define HEADER_MATRIX_MATHS

/* Operator + */
template<class C>
template<class D>
Matrix<C>& Matrix<C>::operator+=(const Matrix<D>& A) {
	if(A._i != _i || A._j != _j){
		throw std::string("Error : Matrix::operator+ : Not the same dimensions between matrices !");
	}

	for(size_t i = 0; i < A._i; ++i){
		for(size_t j = 0; j < A._j; ++j){
			_datas[i][j] += A._datas[i][j];
		}
	}

	return *this;
}

template<class C>
template<class D>
Matrix<C> Matrix<C>::operator+(const Matrix<D>& A) {
	Matrix<C> M = *this;

	M += A;

	return M;
}
/**************/

template<class C>
Matrix<C> Matrix<C>::operator-() {
	Matrix<C> M = *this;

	for(size_t i = 0; i < M._i; ++i){
		for(size_t j = 0; j < M._j; ++j){
			M._datas[i][j] *= -1;
		}
	}

	return M;
}

/* Operator - */
template<class C>
template<class D>
Matrix<C>& Matrix<C>::operator-=(const Matrix<D>& A) {
	if(A._i != _i || A._j != _j){
		throw std::string("Error : Matrix::operator- : Not the same dimensions between matrices !");
	}

	for(size_t i = 0; i < A._i; ++i){
		for(size_t j = 0; j < A._j; ++j){
			_datas[i][j] -= A._datas[i][j];
		}
	}

	return *this;
}

template<class C>
template<class D>
Matrix<C> Matrix<C>::operator-(const Matrix<D>& A) {
	Matrix<C> M = *this;

	M -= A;

	return M;
}
/**************/

template<class C>
Matrix<C> Matrix<C>::transposed(){
	auto M = *this;

	M._datas.clear();
	for(size_t j = 0; j < _j; ++j){
		std::vector<C> data;

		for(size_t i = 0; i < _i; ++i){
			data.push_back(_datas[i][j]);
		}

		M._datas.push_back(data);
	}

	M._j = _i;
	M._i = _j;
	M.test_square();

	return M;
}

/* Operator * */
template<class C>
template<class D>
Matrix<C>& Matrix<C>::operator*=(const D& A) {
	for(size_t i = 0; i < _i; ++i){
		for(size_t j = 0; j < _j; ++j){
			_datas[i][j] *= A;
		}
	}

	return *this;
}

template<class C>
template<class D>
Matrix<C> Matrix<C>::operator*(const D& A) {
	Matrix<C> M = *this;

	M *= A;

	return M;
}

template<class C>
template<class D>
Matrix<C>& Matrix<C>::operator*=(const Matrix<D>& A) {
	if(_j != A._i){
		throw std::string("Error : Matrix::operator* : Not the right dimensions between matrices (") + tos(_j) + ", " + tos(A._i) + ") !";
	}

	auto tmp_datas = _datas;
	init_vect(_i, A._j);

	for(size_t i = 0; i < _i; ++i){
		for(size_t j = 0; j < A._j; ++j){
			for(size_t lc_pos = 0; lc_pos < A._i; ++lc_pos){
				_datas[i][j] += tmp_datas[i][lc_pos] * A._datas[lc_pos][j];
			}
		}
	}

	//_i = _i;
	_j = A._j;
	test_square();

	return *this;
}

template<class C>
template<class D>
Matrix<C> Matrix<C>::operator*(const Matrix<D>& A) {
	Matrix<C> M = *this;

	M *= A;

	return M;
}
/**************/

/* Operator / */
template<class C>
template<class D>
Matrix<C>& Matrix<C>::operator/=(const D& A) {
	for(size_t i = 0; i < _i; ++i){
		for(size_t j = 0; j < _j; ++j){
			_datas[i][j] /= A;
		}
	}

	return *this;
}

template<class C>
template<class D>
Matrix<C> Matrix<C>::operator/(const D& A) {
	Matrix<C> M = *this;

	M /= A;

	return M;
}
/**************/

template<class C>
double Matrix<C>::det(){
	double out = 0;

	if(!_square){
		throw std::string("Error : Matrix::det : The matrix must be square !");
	}

	if(_i == 2){
		out = static_cast<double>(_datas[0][0])*static_cast<double>(_datas[1][1]) - static_cast<double>(_datas[0][1])*static_cast<double>(_datas[1][0]);
		return out;
	}

	std::vector<Matrix<C>> Ms;
	std::vector<double> Cs;
	size_t j = 1;

	for(size_t i = 0; i < _i; ++i){
		Ms.push_back(mineur(i+1, j));
		Cs.push_back(pow(-1, static_cast<double>(i+1+j)));
	}

	for(size_t i = 0; i < _i; ++i){
		out += static_cast<double>(_datas[i][j-1])*(Cs[i]*Ms[i].det());
	}

	return out;
}

template<class C>
Matrix<C> Matrix<C>::inverted(){
	if(det() == 0){
		throw std::string("Error : Matrix::inverted : The matrix's det must be different from 0 !");
	}

	auto id = getIdentity();

	GaussJordan(*this, id, 1, 1);

	return id;
}

#endif //HEADER_MATRIX_MATHS
