#include"Matrix.h"
#include<iostream>

Matrix::Matrix(int row, int col) {
	if (mat != nullptr) { delete[]mat; }
	this->row = row; this->col = col;
	mat = new double[row * col];
	for (int i = 0; i < row * col; i++) { mat[i] = 0; }
}
Matrix::Matrix(int size) {
	row = size; col = size;
	mat = new double[row * col];
	for (int i = 0; i < row * col; i++) {
		mat[i] = 0;
	}
}
Matrix::Matrix() {
	row = 0; col = 0;
	mat = nullptr;
}
Matrix::Matrix(const Matrix& mat2) {
	this->row = mat2.row;
	this->col = mat2.col;
	mat = new double[row * col];
	for (int i = 0; i < row * col; i++) {
		this->mat[i] = mat2.mat[i];
	}
}
Matrix::~Matrix() {
	if (mat != nullptr) { delete[]mat; }
}

void Matrix::input(int row, int col) {
	this->row = row; this->col = col;
	if (mat != nullptr) { delete[]mat; }
	mat = new double[row * col];
	for (int i = 0; i < row * col; i++) {
		std::cout << "Enter " << i + 1 << " element: ";
		std::cin >> mat[i];
	}
}
void Matrix::input(int row, int col, double* mas) {
	this->row = row; this->col = col;
	if (mat != nullptr) { delete[]mat; }
	mat = new double[row * col];
	for (int i = 0; i < row * col; i++) {
		mat[i] = mas[i];
	}
}
void Matrix::randinput(int row, int col) {
	this->row = row; this->col = col;
	if (mat != nullptr) { delete[]mat; }
	mat = new double[row * col];
	for (int i = 0; i < row * col; i++) {
		mat[i] = rand() % 100;
	}
}
void Matrix::print() {
	int k = 0;
	for (int i = 0; i < row * col; i++) {
		if (k == col) {
			std::cout << "\n";
			k = 0;
		}
		std::cout << mat[i] << "\t";
		k++;
	}
	std::cout << "\n";
}
void Matrix::createmat(int row, int col) {
	this->row = row; this->col = col;
	std::cout << "Enter a random matrix or enter it manually: \n";
	std::cout << "1 - random matrix\n2 - manually\n";
	int ans; std::cin >> ans;
	if (ans == 1) {
		this->randinput(this->row, this->col);
	}
	else {
		this->input(this->row, this->col);
	}
}
int Matrix::get_columns() {
	return col;
}
int Matrix::get_rows() {
	return row;
}
double Matrix::get_elem(int i, int j) {
	return mat[i * col + j];
}
bool Matrix::check_null(const Matrix& mat2) {
	if (this->col != mat2.row) { return false; }
	else { return true; }
}
bool Matrix::add(const Matrix& matr)
{
	if (this->row != matr.row) return false;
	if (this->col != matr.col) return false;
	for (int i = 0; i < this->row * this->col; i++)
		this->mat[i] += matr.mat[i];
	return true;
}
Matrix& operator+ (const Matrix& matr1, const Matrix& matr2) {
    Matrix res(matr1);
    res.sum(matr2);
    return res;
}

bool Matrix::operator += (const Matrix& matr) {
	return this->add(matr);
}

Matrix Matrix::sum(const Matrix mat2) {
	//!!!!!!!!!!!!!!!!!
	Matrix mat3(row, col);
	if (this->row != mat2.row || this->col != mat2.col) {
		std::cout << "Matrices must be the same size to perform addition\n";
		std::cout << "Now:\n1 matrix (rows,columns) = (" << this->row << ", " << this->col << ")\n";
		std::cout << "2 matrix (rows,columns) = (" << mat2.row << ", " << mat2.col << ")";
		return mat3;
	}
	for (int i = 0; i < row * col; i++) {
		mat3.mat[i] = mat[i] + mat2.mat[i];
	}
	std::cout << "Sum of matrices: \n";
	mat3.print();
	return mat3;
}
Matrix Matrix::sum(double* mas, int size) {
	Matrix mat3(row, col);
	if (this->row != size || this->col != size) {
		std::cout << "Matrices must be the same size to perform addition\n";
		std::cout << " Now:\n1 matrix (rows,columns) = (" << this->row << " , " << this->col << ")\n";
		std::cout << "2 matrix (rows, columns) = (" << size << ", " << size << ")";
		return mat3;
	}
	for (int i = 0; i < row * col; i++) {
		mat3.mat[i] = mat[i] + mas[i];
	}
	std::cout << "Sum of matrices: \n";
	mat3.print();
	return mat3;
}
Matrix Matrix::mult(const Matrix mat2) {
	//!!!!!!!!!!!!!!!!!
	Matrix mat3(row, mat2.col);
	if (this->col != mat2.row) {
		std::cout << "For matrix multiplication,the number of columns of the first must be equal to the number of rows in second\n";
		std::cout << "Now :\n1 matrix (rows, columns) = ("<<this->row << ", " << this->col << ")\n";
		std::cout << "2 matrix (rows, columns) = (" << mat2.row << ", " << mat2.col << ")";
		return mat3;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < mat2.col; j++) {
			for (int k = 0; k < mat2.row; k++) {
				mat3.mat[i * mat2.col + j] += this->get_elem(i, k) * mat2.mat[k * mat2.col + j];
			}
		}
	}
	std::cout << "Matrix product: \n";
	mat3.print();
	return mat3;
}
Matrix Matrix::mult(double* mas, int size) {
	Matrix mat3(row, size);
	if (this->col != size) {
		std::cout << "For matrix multiplication, the number of columns of the first must be equal to the number of rows of the second\n";
		std::cout << "Now:\n1 matrix (rows, columns) = (" << this->row << ", " << this->col << ")\n";
		std::cout << "2 matrix (rows, columns) = (" << size << ", " << size << ")";
		return mat3;
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < size; j++) {
			for (int k = 0; k < size; k++) {
				mat3.mat[i * size + j] += this->get_elem(i, k) * mas[k * size + j];
			}
		}
	}
	std::cout << "Product of matrices: \n";
	mat3.print();
	return mat3;
}
void Matrix::shiftmat(Matrix& addmat, int index) {
	int ki = 0;
	int size = this->row;
	for (int i = 1; i < size; i++) {
		for (int j = 0, kj = 0; j < size; j++) {
			if (j != index) {
				addmat.mat[ki * addmat.row + kj] = this->mat[i * size + j];
				kj++;
			}
		}
		ki++;
	}
}
double Matrix::det(int& a) {
	//!!!!!!!!!!!!!!!!!
	if (row != col) {
		std::cout << "He can not find the determinant\nThe matrix must be square\n";
		return -1;
	}
	int f = a;
	double opred = 0;
	int size = this->row;
	int k = 1;
	if (size < 1) { return 0; }
	else if (size == 1) { opred = mat[0]; }
	else if (size == 2) { opred = mat[0] * mat[3] - mat[1] * mat[2]; }
	else {
		for (int i = 0; i < size; i++) {
			f++;
			int m = size - 1;
			Matrix addmat(m);
			this->shiftmat(addmat, i);
			opred = opred + k * this->mat[i] * addmat.det(f);
			k = -k;
		}
	}
	if (row == a) {
		std::cout << "First matrix:\n";
		this->print();
		std::cout << "\nDeterminant: "<< opred << "\n";
		return 0;
	}
	else {
		return opred;
	}
}
double Matrix::trace() {
	//!!!!!!!!!!!!!!!!!
	if (row != col) {
		std::cout << "Unable to find trace\nMatrix must be square\n";
		return 0;
	}
	double summ = 0; int flag = row % 2;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (i == j || (i + j) == row - 1) {
				summ += this->get_elem(i, j);
			}
		}
	}
	std::cout << "First matrix:\n";
	this->print();
	std::cout << "trace: " << summ << "\n";
	return 0;
}
Matrix Matrix::mult_by_num(double num) {
	Matrix mat3(row, col);
	for (int i = 0; i < row * col; i++) { mat3.mat[i] = mat[i] * num; }
	return mat3;
}