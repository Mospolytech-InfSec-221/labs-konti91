#include <iostream>
#include <limits>
#include <string>
#include <list>

#define russianIO(x)	system("chcp 1251>nul");\
						x;\
						system("chcp 65001>nul")

using std::string;
using std::list;
using std::cout;
using std::cin;
using std::endl;

void fix() {
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool compare(string st1, string st2) {
	int num1 = std::stoi(st1.substr(0, st1.find(" ")).erase(st1.find("-"), 1));
	int num2 = std::stoi(st2.substr(0, st2.find(" ")).erase(st2.find("-"), 1));

	return num1 < num2;
}

int main() {
	system("chcp 65001>nul");
	string s;
	string groupname = "";
	list<string> students;
	int option;
	while (true) {
		cout << "Select an action:\n"
			<< "1. Add a note\n"
			<< "2. List students in groups\n"
			<< "3. Exit\n"
			<< "Your choice: ";
		cin >> option;
		switch (option) {
		case 1:
			fix();
			cout << "Enter the group and the last name of the student separated by a space: ";
			russianIO(std::getline(cin, s));
			students.push_back(s);
			break;
		case 2:
			students.sort(compare);
			russianIO(for (auto student : students) {
				if (groupname != student.substr(0, student.find(" "))) {
					groupname = student.substr(0, student.find(" "));
					cout << groupname << endl;
				}
				cout << "\t\t" << student.substr(student.find(" ")) << endl;
			});
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