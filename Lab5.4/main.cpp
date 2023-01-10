#include <iostream>
#include "Position.h"
#include "Square.h"
#include "Circle.h"
#include "CircleInSquare.h"

using std::cout;
using std::cin;
using std::endl;

int main() {
	system("chcp 65001 > nul");
	int option;
	int x, y, side, diameter;
	Position pos;
	Circle circle;
	Square square;
	CircleInSquare C_I_S;
	while (true) {
		cout << "Select an action:\n"
			<< "1. Create a point\n"
			<< "2. Create a square\n"
			<< "3. Create a circle\n"
			<< "4. Create a circle in a square\n"
			<< "5. Exit\n"
			<< "6. Exit\n"
			<< "Your choice: ";
		cin >> option;
		switch (option) {
		case 1:
			cout << "Enter point coordinates: " << endl;
			cout << "X = ";
			cin >> x;
			cout << "Y = ";
			cin >> y;
			pos.setXY(x, y);
			break;
		case 2:
			cout << "Enter square coordinates: " << endl;
			cout << "X = ";
			cin >> x;
			cout << "Y = ";
			cin >> y;
			cout << "Enter the length of the side of the square: ";
			cin >> side;
			square.setXY(x, y);
			square.setSize(side);
			break;
		case 3:
			cout << "Enter circle coordinates: " << endl;
			cout << "X = ";
			cin >> x;
			cout << "Y = ";
			cin >> y;
			cout << "Enter circle diameter: ";
			cin >> diameter;
			circle.setXY(x, y);
			circle.setDiameter(diameter);
			break;
		case 4:
			cout << "Enter the coordinates of the inscribed circle: " << endl;
			cout << "X = ";
			cin >> x;
			cout << "Y = ";
			cin >> y;
			cout << "Enter the length of the side of the square: ";
			cin >> side;
			cout << "Enter circle diameter: ";
			cin >> diameter;
			C_I_S.setXY(x, y);
			C_I_S.setSize(side);
			C_I_S.setDiameter(diameter);
			break;
		case 5:
			system("cls");
			cout << "Select the item you would like to display:\n"
				<< "1. Point\n"
				<< "2. Square\n"
				<< "3. Circle\n"
				<< "4. Circle inscribed in a square\n"
				<< "5. Side of a square\n"
				<< "6. Circle Diameter\n"
				<< "7. The side of the square in which the circle is inscribed\n"
				<< "8. Inscribed circle diameter\n"
				<< "9. Back\n"
				<< "Your choice: ";
			cin >> option;
			switch (option) {
			case 1:
				cout << pos;
				break;
			case 2:
				cout << square;
				break;
			case 3:
				cout << circle;
				break;
			case 4:
				cout << C_I_S;
				break;
			case 5:
				cout << square.getSize() << endl;
				break;
			case 6:
				cout << circle.getDiameter() << endl;
				break;
			case 7:
				cout << C_I_S.getSize() << endl;
				break;
			case 8:
				cout << C_I_S.getDiameter() << endl;
				break;
			case 9:
			default:
				break;
			}
			break;
		case 6:
			return 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}


