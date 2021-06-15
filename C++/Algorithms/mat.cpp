//naive algorithms for matrix algebra
// by Dave Amiana (2021)
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Matrix; 

//helper function that guarantees square matrix assumption
bool is_square(const Matrix& A, const Matrix& B){
	if(A.size() != B.size()) return false;
	for(size_t i = 0; i < A.size(); ++i){
		if(A[i].size() != B[i].size()){
			return false;
		}
	}
	return true;
}

//valid for square matrix
Matrix operator*(const Matrix& A, const Matrix& B){
	if(!is_square(A,B)) throw std::exception();
	
	Matrix C = std::move(B); // move asignment
	for(size_t i = 0; i < B.size(); ++i){
		for(size_t j =0; j < B.size(); ++j){
			C[i][j] = 0;
			for(size_t k = 0; k < B.size(); ++k)
				C[i][j] = C[i][j] + A[i][k]*B[k][j]; 	
		}
	}
	return C;
}

Matrix operator*(const Matrix& A, int scalar){
	Matrix C = std::move(A); // move asignment
	for(size_t i = 0; i < A.size(); ++i){
		for(size_t j =0; j < A.size(); ++j){
			C[i][j] = 0;
			C[i][j] = scalar * A[i][j];
		}
	}
	return C;
}

Matrix operator+(const Matrix& A, const Matrix& B){
	if(!is_square(A,B)) throw std::exception();
	
	Matrix C = std::move(B); // move asignment
	for(size_t i = 0; i < B.size(); ++i){
		for(size_t j =0; j < B.size(); ++j){
			C[i][j] = 0;
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	return C;
}

Matrix operator-(const Matrix& A, const Matrix& B){
	if(!is_square(A,B)) throw std::exception();
	
	Matrix C = std::move(B); // move asignment
	for(size_t i = 0; i < B.size(); ++i){
		for(size_t j =0; j < B.size(); ++j){
			C[i][j] = 0;
			C[i][j] = A[i][j] - B[i][j];
		}
	}
	return C;
}

std::ostream& operator<< (std::ostream& ss, const Matrix& matrix){
	for(size_t i = 0; i < matrix.size(); ++i){
		for(size_t j = 0; j < matrix.size(); ++j)
			ss << matrix[i][j] << " ";
		ss << std::endl;
	}
	return ss;
}

int main(){
	// assumes n*n matrix
	Matrix A {{10,20,10},{4,5,6}, {2,3,5}};
	Matrix B{{3,2,4},{3,3,9},{4,4,2}};
	std::cout << A*3;
}
