#include <iostream>
using namespace std;

typedef bool (*sort_criteria) (int, int);

void array_output(int* mas, int size) {
	cout << "Array Size " << size << ":\n";
	for (int i = 0; i < size; i++) {
		cout << mas[i] << " ";
	}
	cout << endl;
}

void array_input(int* mas, int size) {
	cout << "Enter the elements of the array into a string separated by a space:\n";
	for (int i = 0; i < size; i++) {
		cin >> mas[i];
	}
}

int sum_chet(int param) {
	int sum = 0;
	bool chet = false;
	while (param != 0) {
		if (chet) sum += param % 10;
		chet = !chet;
		param /= 10;
	}
	return sum;
}

bool criteria_chet(int param1, int param2) {
	return (sum_chet(param1) > sum_chet(param2)) ? true : false;
}

void sort(int* mas, int size, sort_criteria func) {
	int temp;
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (func(mas[j], mas[j+1])) {
				temp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = temp;
			}
		}
    }
}

bool sort_last(int param1, int param2) {
	if (param1 % 10 > param2 % 10) return true;
	else if (param1 % 10 == param2 % 10) return (param1 < param2) ? true : false;
	else return false;
}

int* create(int &size) {
	while (true) {
		cout << "Enter Array Size: ";
		cin >> size;
		if (size > 0 && size <= 1000) break;
		else cout << "Mistake. Re-enter. n must be greater than 0 and less than 1000\n";
	}
	int* mas = new int[size];
	return mas;
}

void free(int* mas) {
	delete[] mas;
}

int main(int argc, char** argv) {
	int n = 0;
	int* mas = NULL;
	char option;
	while (true) {
		cout << "Select an action:\n"
			<< "1. Matrix Input\n"
			<< "2. Matrix Output\n"
			<< "3. Sorting by the sum of even numbered digits\n"
			<< "4. Sort array first by ascending last digit,\n   and if the last digits match - in descending order\n"
			<< "5. Exit\n"
			<< "Your Choice: ";
		cin >> option;
		switch (option) {
		case '1':
			mas = create(n);
			array_input(mas, n);
			break;
		case '2':
			if (n != 0) array_output(mas, n);
			break;
		case '3':
			sort(mas, n, criteria_chet);
			array_output(mas, n);
			break;
		case '4':
			sort(mas, n, sort_last);
			break;
		case '5':
			if (n != 0) free(mas);
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}
