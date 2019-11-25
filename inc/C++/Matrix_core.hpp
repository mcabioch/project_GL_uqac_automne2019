/*!
*
*	\file		Matrix_core.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Sunday September, 15 2019 19:17:03
*	\modified	Sunday September, 16 2019
*
*/
#ifndef HEADER_MATRIX_CORE
#define HEADER_MATRIX_CORE

template<class C>
void Matrix<C>::test_square(){
	_square = (_i == _j);
}

template<class C>
Matrix<C> Matrix<C>::mineur(size_t i, size_t j){
	std::vector<std::vector<C>> datas;

	for(size_t index_i = 0; index_i < _i; ++index_i){
		std::vector<C> data;

		if(index_i + 1 == i){
			continue;
		}
		for(size_t index_j = 0; index_j < _j; ++index_j){
			if(index_j + 1 == j){
				continue;
			}
			data.push_back(_datas[index_i][index_j]);
		}

		datas.push_back(data);
	}

	Matrix<C> M(datas);
	return M;
}

template<class C>
Matrix<C> Matrix<C>::getIdentity(){
	if(!_square){
		throw std::string("Error : Matrix::getIdentity : The matrix must be square !");
	}

	auto datas = _datas;

	for(size_t i = 0; i < _i; ++i){
		for(size_t j = 0; j < _j; ++j){
			if(i == j){
				datas[i][j] = 1;
			} else {
				datas[i][j] = 0;
			}
		}
	}

	return Matrix<C>(datas);
}

template<class C>
template<class T>
std::string Matrix<C>::tos(T value){
	std::stringstream sstream(std::stringstream::in | std::stringstream::out);
	sstream << value;
	return sstream.str();
}

#endif //HEADER_MATRIX_CORE
