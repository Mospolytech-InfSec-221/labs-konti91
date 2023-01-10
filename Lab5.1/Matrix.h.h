#pragma once
class Matrix {
private:
	int row;
	int col;
	double* mat;
public:
	Matrix(int rows, int cols);
	Matrix(int size);
	Matrix();
	Matrix(const Matrix& other);
	~Matrix();

	void input(int cols, int rows);
	void input(int cols, int rows, double* mas);
	void randinput(int cols, int rows);
	void print();
	void createmat(int cols, int rows);
	int get_columns();
	int get_rows();
	double get_elem(int i, int j);
	bool check_null(const Matrix& mat2);
	bool operator+= (const Matrix& matr);
	bool add(const Matrix& MatrB);

	Matrix sum(const Matrix mat2);
	Matrix sum(double* mas, int size);
	Matrix mult(const Matrix mat2);
	Matrix mult(double* mas, int size);
	double trace();
	void shiftmat(Matrix& addmat, int index);
	double det(int& a);
	Matrix mult_by_num(double num);
};

Matrix& operator+ (const Matrix& matr1, const Matrix& matr2);