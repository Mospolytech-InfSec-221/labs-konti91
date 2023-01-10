#include<iostream>
using namespace std;

int main () 
{
        std::string binary_rep;
        int mask = 0b10000000000000000000000000000000;int number = 3;
        for (int i = 0; i < 32; i++) {
            binary_rep += std::to_string((number&mask) == 0 ? 0 : 1);
            number <<= 1;
        }
}
