#include <iostream>
using namespace std;

int main() {
    int x1, x2, y1, y2;
    double x12, y12;
    cin >> x1 >> y1;
    cout << x1 << y1;
    cin >> x2 >> y2;
    cout << x2 << y2;
    x12 = (x1 + x2) / 2.;
    y12 = (y2 + y2) / 2.;
    cout << ": [" << x12 << "; " << y12 << "].\n";
    return 0;
}
