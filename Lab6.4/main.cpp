#include <iostream>
#include <deque>
#include <set>

using std::deque;
using std::set;
using std::string;
using std::cout;
using std::cin;
using std::endl;

string getstring() {
	string s;
	system("chcp 1251>nul");
	cin >> s;
	system("chcp 65001>nul");
	return s;
}

struct _test_data {
	string username;
	uint16_t mark;
};

int main() {
	_test_data test;
	deque<_test_data> tests;
	set<string> tests_usernames;
	system("chcp 1251 > nul");
	int option;
	while (true) {
		cout << "Select an action:\n"
			<< "1. Enter Data\n"
			<< "2. View Database\n"
			<< "3. Exit\n"
			<< "Your Choice: ";
		cin >> option;
		switch (option) {
		case 1:
			cout << "Enter username and test results:\nUsername: ";
			test.username = getstring();
			cout << "Mark: ";
			cin >> test.mark;
			if (tests_usernames.find(test.username) == tests_usernames.end()) {
				tests_usernames.insert(test.username);
				tests.push_back(test);
			}
			else cout << "The user has already finished this test, the results are not longer in this account\n";
			break;
		case 2:
			for (auto x : tests) {
				cout << "Username: ";
				system("chcp 1251>nul");
				cout << x.username;
				system("chcp 65001>nul");
				cout << "\nMark: " << x.mark << endl;
			}
			break;
		case 3:
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}
