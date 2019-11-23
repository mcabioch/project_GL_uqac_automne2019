/*!
*
*	\file		Matrix_constructs.hpp
*	\author		Mathias CABIOCH-DELALANDE
*	\created	Sunday September, 15 2019 19:17:03
*	\modified	Sunday September, 16 2019
*
*/
#ifndef HEADER_MATRIX_CONSTRUCTS
#define HEADER_MATRIX_CONSTRUCTS

template<class C>
Matrix<C>::Matrix() :
	_enabled(false),
	_square(true),
	_datas(),
	_i(0),
	_j(0)
{
	
}

template<class C>
Matrix<C>::Matrix(const std::vector<std::vector<C>>& datas) :
	Matrix()
{
	init(datas);
}

template<class C>
template<std::size_t M, std::size_t N>
Matrix<C>::Matrix(std::array<std::array<C, M>, N>& datas) :
	Matrix()
{
	std::vector<std::vector<C>> formatted_datas;

	for(auto data : datas){
		std::vector<C> formatted_data(data.begin(), data.end());
		formatted_datas.push_back(formatted_data);
	}

	init(formatted_datas);
}

template<class C>
void Matrix<C>::init_vect(size_t i, size_t j, C default_value){
	_datas.clear();

	for(size_t index_i = 0; index_i < i; ++index_i){
		std::vector<C> data;

		for(size_t index_j = 0; index_j < j; ++index_j){
			data.push_back(default_value);
		}

		_datas.push_back(data);
	}

	_i = i;
	_j = j;
}

template<class C>
void Matrix<C>::init(const std::vector<std::vector<C>>& datas){
	_enabled = true;

	size_t maxI = 0;
	size_t maxJ = 0;

	std::vector<std::vector<C>> formatted_datas;
	for(auto line : datas){
		maxI++;
		std::vector<C> formatted_line = line;

		if(maxJ < line.size()){
			maxJ = line.size();
		} else {
			for(size_t i = line.size(); i < maxJ; ++i){
				formatted_line.push_back(0);
			}
		}

		formatted_datas.push_back(formatted_line);
	}

	for(auto& formatted_line : formatted_datas){
		if(formatted_line.size() < maxJ){
			for(size_t i = formatted_line.size(); i < maxJ; ++i){
				formatted_line.push_back(0);
			}
		}
	}

	_i = maxI;
	_j = maxJ;
	_datas = formatted_datas;

	if(_i != _j){
		_square = false;
	}
}

#endif //HEADER_MATRIX_CONSTRUCTS
