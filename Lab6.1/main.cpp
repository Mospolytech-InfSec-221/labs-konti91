#include <iostream>
#include <stack>
#include "Stack.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

bool checkSym(char sym1, char sym2) {
	switch (sym1) {
	case '[':
		return ']' == sym2;
	case '(':
		return ')' == sym2;
	case '{':
		return '}' == sym2;
	default:
		return false;
	}
}

template <class T>
bool check(string s) {
	T st;
	for (char sym : s) {
		if (sym == '(' || sym == '[' || sym == '{') st.push(sym);
		else if (sym == ')' || sym == ']' || sym == '}') {
			if (!st.empty() && checkSym(st.top(), sym)) st.pop();
			else return false;
		}
	}
	if (!st.empty()) {
		while (!st.empty()) st.pop();
		return false;
	}
	return true;
}

int main() {
	system("chcp 1251 > nul");
	int option;
	string s;
	while (true) {
		cout << "Select an action:\n"
			<< "1. Enter string\n"
			<< "2. Print string\n"
			<< "3. Check parentheses for correctness by built-in stack class\n"
			<< "4. Check parentheses for correctness with own stack class\n"
			<< "5. Exit\n"
			<< "Your choice: ";
		cin >> option;
		switch (option) {
		case 1:
			cout << "Enter the string: ";
			cin >> s;
			break;
		case 2:
			cout << "Row: " << s << endl;
			break;
		case 3:
			if (check<std::stack<char>>(s)) cout << "Parentheses in the row are placed correctly\n";
			else cout << "Parentheses in the row are not placed correctly\n";
			break;
		case 4:
			if (check<Stack<char>>(s)) cout << "Parentheses in the row are placed correctly\n";
			else cout << "Parentheses in the row are not placed correctly\n";
			break;
		case 5:
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}

