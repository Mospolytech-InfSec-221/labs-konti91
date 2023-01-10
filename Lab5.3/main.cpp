#include <iostream>
#include <stdexcept>
#include "Matrix.h"

using std::cout;
using std::cin;
using std::endl;
using std::exception;

int main() {
	system("chcp 65001 > nul");
	int option;
	Matrix matr1, matr2, prom;
	double mnoj;
	int n, m;
	while (true) {
		try {
			cout << "Select an action:\n"
				<< "1. Enter new matrix\n"
				<< "2. Enter additional matrix\n"
				<< "3. Output matrix\n"
				<< "4. Find the sum of the two matrices\n"
				<< "5. Find difference of the two matrices\n"
				<< "6. Change the sign of the matrix elements\n"
				<< "7. Multiply the main matrix by the auxiliary\n"
				<< "8. Multiply a matrix by a number\n"
				<< "9. Matrix determinat\n"
				<< "10. Matrix trace\n"
				<< "11. Number of matrix columns\n"
				<< "12. Output element i of row j of column\n"
				<< "13. Exit\n"
				<< "Your choice: ";
			cin >> option;
			switch (option) {
			case 1:
				cout << "Enter the rank of the main matrix: ";
				cin >> matr1;
				break;
			case 2:
				cout << "Enter the rank of the auxiliary matrix: ";
				cin >> matr2;
				break;
			case 3:
				cout << "What matrix do you want to output?\n"
					<< "1. Main\n"
					<< "2. Auxiliary\n"
					<< "Your choice: ";
				cin >> m;
				if (m == 1) cout << matr1;
				else cout << matr2;
				break;
			case 4:
				cout << matr1 + matr2;
				break;
			case 5:
				cout << matr1 - matr2;
				break;
			case 6:
				cout << -matr1;
				break;
			case 7:
				cout << matr1 * matr2;
				break;
			case 8:
				cout << "Enter multiplier: ";
				cin >> mnoj;
				cout << matr1 * mnoj;
				break;
			case 9:
				cout << "The matrix determinant is: " << matr1.det() << endl;
				break;
			case 10:
				cout << "The trace of the matrix is: " << matr1.tr() << endl;
				break;
			case 11:
				cout << "Number of columns in the matrix: " << matr1.get_columns() << endl;
				break;
			case 12:
				cout << "Enter the indexes of the element you are looking for, separated by a space: ";
				cin >> n >> m;
				cout << "Element matr1[" << n << ", " << m << "] = " << matr1.get_elem(n, m) << endl;
				break;
			case 13:
				return 0;
			default:
				break;
			}
		}
		catch (exception e) {
			cout << e.what() << endl;
		}
		n = m = 0;
		system("pause");
		system("cls");
	}
}


