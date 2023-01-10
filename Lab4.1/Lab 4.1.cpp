#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

char* input(int size) {
	char* rez = new char[size];
	cout << "Enter the string: ";
	system("chcp 1251 > nul");
	cin.getline(rez, size);
	system("chcp 65001 > nul");
	return rez;
}

char tolower(char symb) {
	if ((int)symb < -32 && (int)symb > -65 || (int)symb < 91 && (int)symb > 64) return (char)((int)symb + 32);
	else return symb;
}

bool palindrom(const char* str) {
	int length = strlen(str);
	for (int i = 0, j = length - 1; i < j; i++, j--) {
		if (str[i] == ' ') i++;
		if (str[j] == ' ') j--;
		if (tolower(str[i]) != tolower(str[j])) return false;
	}
	return true;
}

int find_substring1(const char* str_for_search_in, const char* substring, int start_position) {
	int pos = -1;
	for (int i = start_position; i < strlen(str_for_search_in); i++) {
		if (tolower(str_for_search_in[i]) == tolower(substring[0])) {
			pos = i;
			i++;
			for (int j = 1; j < strlen(substring); j++, i++) {
				if (tolower(str_for_search_in[i]) != tolower(substring[j])) {
					pos = -1;
					break;
				}
			}
			if (pos != -1) return pos;
		}
	}
	return pos;
}

std::vector<int> find_substring2(const char* str_for_search_in, const char* substring) {
	std::vector<int> arr;
	int step = strlen(substring) - 1;
	int prom;
	int* rez = nullptr;
	for (int i = 0; i < strlen(str_for_search_in); i++) {
		prom = find_substring1(str_for_search_in, substring, i);
		if (prom > -1) {
			arr.push_back(prom);
			i = prom + step;
		}
	}
	return arr;
}

void encrypt(char* str_for_encrypt, int key) {
	for (int i = 0; i < strlen(str_for_encrypt); i++) {
		str_for_encrypt[i] = (char)((int)str_for_encrypt[i] + key);
	}
}

void search_name(const char * str) {
    system("chcp 1251>nul");
	bool flag = false;
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '\"') {
			if (flag) {
				cout << endl;
				flag = false;
			}
			else flag = true;
			continue;
		}
		if (flag) cout << str[i];
	}
	system("chcp 65001>nul");
}

int main(int argc, char** argv) {
	system("chcp 65001 > nul");
	char* str;
	char* substr;
	std::vector<int> pos_mas;
	int key;
	char option;
	while (true) {
		cout << "Select an action:\n"
			<< "1. Palindrome check\n"
			<< "2. Substring search\n"
			<< "3. Caesar's cipher\n"
			<< "4. Title Search\n"
			<< "5. Exit\n"
			<< "Your choice: ";
		cin >> option;
		switch (option) {
		case '1':
			cin.ignore();
			str = input(255);
			if (palindrom(str)) cout << "The string you entered is a palindrome\n";
			else cout << "The string you entered is not a palindrome\n";
			delete[] str;
			break;
		case '2':
			cin.ignore();
			str = input(255);
			substr = input(10);
			cout << "Substring position: " << find_substring1(str, substr, 0) << endl;
			pos_mas = find_substring2(str, substr);
			for (int x: pos_mas) {
				cout << x << " ";
			}
			cout << endl;
			delete[] str;
			delete[] substr;
			break;
		case '3':
			cout << "Enter mixing: ";
			cin >> key;
			cin.ignore();
			str = input(255);
			encrypt(str, key);
			cout << "Result: ";
			system("chcp 1251>nul");
			cout << str << endl;
			system("chcp 65001>nul");
			delete[] str;
			break;
		case '4':
			cin.ignore();
			str = input(255);
			search_name(str);
			delete[] str;
			break;
		case '5':
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}

