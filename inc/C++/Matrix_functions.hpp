/*!
*
*	\file		Matrix_functions.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Sunday September, 15 2019 19:17:03
*	\modified	September, 26 2019
*
*/
#ifndef HEADER_MATRIX_FUNCTIONS
#define HEADER_MATRIX_FUNCTIONS

template<class D>
void GaussJordan(const Matrix<D>& M, Matrix<D>& I, size_t i, size_t j){
	if(i == 0 || j == 0 || i > M._i || j > M._j){
		throw std::string("Error : GaussJordan : Wrong boundaries !");
	}

	Matrix<D> inside_M = M;

	for(size_t index_i = 0; index_i < inside_M._i && inside_M._datas[i-1][j-1] == 0; ++index_i){
		if(index_i == i-1){
			continue;
		}

		if(inside_M._datas[index_i][j-1] != 0){
			auto tmp = inside_M._datas[index_i];
			inside_M._datas[index_i] = inside_M._datas[i-1];
			inside_M._datas[i-1] = tmp;
		}
	}

	for(size_t index_i = 0; index_i < inside_M._i; ++index_i){
		auto coef = inside_M._datas[index_i][j-1] / inside_M._datas[i-1][j-1];

		for(size_t index_j = 0; index_j < inside_M._j; ++index_j){
			if(index_i == i-1){
				inside_M._datas[index_i][index_j] /= coef;
				I._datas[index_i][index_j] /= coef;
			} else {
				inside_M._datas[index_i][index_j] -= coef*inside_M._datas[i-1][index_j];
				I._datas[index_i][index_j] -= coef*I._datas[i-1][index_j];
			}
		}
	}

	if(i == inside_M._i){
		for(size_t index_i = 0; index_i < inside_M._i; ++index_i){
			auto coef = inside_M._datas[index_i][index_i];

			for(size_t index_j = 0; index_j < inside_M._j; ++index_j){
				inside_M._datas[index_i][index_j] /= coef;
				I._datas[index_i][index_j] /= coef;
			}
		}

		return;
	}

	GaussJordan(inside_M, I, i+1, j+1);
}

template<class D>
std::ostream& operator<<(std::ostream& os, const Matrix<D>& M){
	size_t max_length = 0;

	for(size_t i = 0; i < M._i; ++i){
		for(size_t j = 0; j < M._j; ++j){
			auto str_val = Matrix<D>::tos(M(i+1, j+1));

			if(str_val.size() > max_length){
				max_length = str_val.size();
			}
		}
	}

	for(size_t i = 0; i < M._i; ++i){
		for(size_t j = 0; j < M._j; ++j){
			auto str_val = Matrix<D>::tos(M(i+1, j+1));

			for(size_t spaces = 0; spaces < max_length-str_val.size(); ++spaces){
				os << " ";
			}
			os << str_val;

			if(j+1 < M._j){
				os << " ";
			}
		}

		if(i+1 < M._i){
			os << "\n";
		}
	}

	return os;
}

template<class C, typename U>
Matrix<C> mod(const Matrix<C>& M, U b, bool positive = false){
	Matrix<C> out = M;

	for(size_t i = 0; i < out.i(); ++i){
		for(size_t j = 0; j < out.j(); ++j){
			out(i+1, j+1) = mod(M(i+1, j+1), b, positive);
		}
	}

	return out;
}

#endif //HEADER_MATRIX_FUNCTIONS
