#include <iostream>
using namespace std;

void task2() {
    int n;
    cin >> n;
    for (signed int i = 0; i<= n; i++)
    for (signed int j = 0; j<= i; j++)
    cout << j;
    cout << endl;
}


void task1() {
    int n;
    cin >> n;
    cout<< "binomial sequence:\n";
  double res = 1.;
    cout << res << " ";
  for (signed int k = 1; k <= n; k++)
            res *= (n - (k - 1.)) / k;
      cout << res << " ";
     cout << endl;
}

            
void task3() {
    int a, sum = 0, n = 0;
    cout << "Enter a sequence of numbers with a number line. Mark the end of input with d.\n";
    double average;
    std::string buffer = "";
    while (buffer != "d") {
        cin >> buffer;
        if (buffer == "d") break;
        try {
            a = std::stoi(buffer);
            sum += a;
            n++;
        }
        catch (std::invalid_argument e) {
            cout << buffer << "It does not count a number. It will not count towards the total\n";
        }
    }
    average = (double) sum / n;
    cout << "The average value of the coordinates is: " << average << endl;
}

int main() {
    int choice = 0;
    while (true) {
        std:: cout << "What task you would like to see?\n"
        << "1.task 1\n"
        << "2.task 2\n"
        << "3.task 3\n";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                task1();
                break;
            }
            case 2: {
                task2();
                break;
            }
            case 3: {
                task3();
                break;
            }
            default: {
                return 0;
            }
        }
    }
}
  
