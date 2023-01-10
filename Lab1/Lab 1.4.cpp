#include <iostream>
using namespace std;

int main() {
    int a, b;
    double res;
    cout<< "4.\nEnter Odds a * x = b: ";
    cin >> a >> b;
    cout << a << " * x = " << b;
    cout << "\nx = " << b << " / " << a;
    cout << "\nx = " << (res = double(b) / a);
    cout << "\nAnswer: " << res << ".\n";
}