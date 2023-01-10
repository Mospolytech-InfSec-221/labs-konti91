#include<iostream>
#include"Matrix.h"

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int choise = 0;

	Matrix mat1(4);
	Matrix mat2(4);
	while (true) {
		std::cout << "What command to execute: \n";
		std::cout << "1 - Matrix Input\n2 - Matrix Printing\n3 - Print number of matrix rows\n4 - Print number of matrix columns\n5 - Print (i, j) element\n";
		std::cout << "6 - sum of matrices\n7 - matrix multiplication\n8 - matrix trace print\n9 - matrix determinant print\n10 - multiplication of a matrix by a number\n11 - Exit\n";
		std::cout << "Enter team number: "; std::cin >> choise;
		switch (choise) {
		case 1: {
			system("cls");
			std::cout << "Which matrix to complete?\n1 - First\n2 - Second\n";
			int ans; std::cin >> ans;
			std::cout << "Enter matrix size: \nNumber of rows - ";
			int rw; std::cin >> rw; std::cout << "Number of columns - "; int cl; std::cin >> cl;
			if (ans == 1) {
				mat1.createmat(rw, cl);
			}
			else {
				mat2.createmat(rw, cl);
			}
			std::cout << "Matrix created\n\n";
			break;
		}
		case 2: {
			system("cls");
			std::cout << "What matrix to display?\n1 - First\n2 - Second\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				mat1.print();
			}
			else {
				mat2.print();
			}
			std::cout << "\n";
			break;
		}
		case 3: {
			system("cls");
			std::cout << "Number of rows of which matrix to display?\n1 - First\n2 - Second\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "Number of rows of the first matrix = " << mat1.get_rows() << "\n\n";
			}
			else {
				std::cout << "Number of columns of the first matrix = " << mat2.get_rows() << "\n\n";
			}
			break;
		}
		case 4: {
			system("cls");
			std::cout << "Number of columns of which matrix to display?\n1 - первой\n2 - второй\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "Number of columns of the first matrix = " << mat1.get_columns() << "\n\n";
			}
			else {
				std::cout << "Number of columns of the first matrix = " << mat2.get_columns() << "\n\n";
			}
			break;
		}
		case 5: {
			system("cls");
			std::cout << "From which matrix to derive (i,j) element?\n1 - From the first\n2 - From the second\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "Enter the row number(from 0 to " << mat1.get_rows() - 1 << "): "; int ans_i; std::cin >> ans_i;
				std::cout << "Enter the column number(number from 0 to " << mat1.get_columns() - 1 << "): "; int ans_j; std::cin >> ans_j;
				std::cout << "Matrix: \n";
				mat1.print();
				std::cout << "Element at the position = " << mat1.get_elem(ans_i, ans_j);
			}
			else {
				std::cout << "Enter the row number(number from 0 to " << mat2.get_rows() - 1 << "): "; int ans_i; std::cin >> ans_i;
				std::cout << "Enter the column number(number from 0 to " << mat2.get_columns() - 1 << "): "; int ans_j; std::cin >> ans_j;
				std::cout << "Matrix: \n";
				mat2.print();
				std::cout << "Element at the position = " << mat2.get_elem(ans_i, ans_j);
			}
			std::cout << "\n\n";
			break;
		}
		case 6: {
			system("cls");
			Matrix matr;
			mat1 += mat2;
			mat1 + mat2;
			mat1.sum(mat2);
			std::cout << "\n\n";
			mat1.print();
			std::cout << "\n\n";
			break;
		}
		case 7: {
			system("cls");
			mat1.mult(mat2);
			std::cout << "\n\n";
			break;
		}
		case 8: {
			system("cls");
			std::cout << "The trace of which matrix to display?\n1 - The trace of first matrix\n2 - The trace of second matrix\n";
			int ans; std::cin >> ans;
			system("cls");
			if (ans == 1) {
				mat1.trace();
			}
			else {
				mat2.trace();
			}
			std::cout << "\n";
			break;
		}
		case 9: {
			system("cls");
			std::cout << "The determinant of which matrix to display?\n1 - The determinat of first matrix\n2 - The determinat of second matrix\n";
			int ans; std::cin >> ans;
			system("cls");
			if (ans == 1) {
				int f = mat1.get_columns();
				mat1.det(f);
			}
			else {
				int f = mat2.get_columns();
				mat2.det(f);
			}
			std::cout << "\n";
			break;
		}
		case 10: {
			system("cls");
			std::cout << "Enter the number by which to multiply the matrix: ";
			int k;  std::cin >> k;
			std::cout << "Which matrix to multiply by " << k << "?\n1 - The first\n2 - The second\n";
			int ans; std::cin >> ans;
			if (ans == 1) {
				std::cout << "Matrix before multiplication: \n";
				mat1.print();
				Matrix mat3(mat1.mult_by_num(k));
				std::cout << "Matrix after multiplication:\n";
				mat3.print();
			}
			else {
				std::cout << "Matrix before multiplication: \n";
				mat2.print();
				Matrix mat3(mat2.mult_by_num(k));
				std::cout << "Matrix after multiplication:\n";
				mat3.print();
			}
			break;
		}
		case 11: {
			return 0;
		}
		default:
			std::cout << "Error\n";
			continue;
		}
	}
	return 0;
}


