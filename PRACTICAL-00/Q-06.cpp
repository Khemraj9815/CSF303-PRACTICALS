#include <iostream>
#include <string>
#include <cctype> 
#include <algorithm> 
using namespace std;

int main() {
    string name = "Khem Raj Ghalley";
    int length_of_first_word = name.find(' ');

    cout << "Name repeated" << "(" << length_of_first_word << " times):" << endl;
    for (int i = 1; i <=length_of_first_word; i++) {
        cout << name.substr(0, length_of_first_word) << endl;
    }

    int height = 16;
    cout << "Triangle (height = 16" << endl;
    for (int i=1; i <=16; i++) {
        cout << string(i, '*') << endl;
    }
    cout << "Time Table for 8 (last digit of 2230286)";
    int n = 8;
    for (int i = 0; i <= 10; i++) {
        cout << n <<  "*" << i << "=" << n * i << endl;
    }

}