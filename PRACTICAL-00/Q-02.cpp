#include <iostream>
#include <string>
using namespace std;

int main() {
    int std_no = 2230286;
    int sum = 0;

    for (int temp = std_no; temp > 0; temp /= 10) {
        sum += temp % 10;
    }
    
    if (std_no % 2 ==0 ) {
        cout << std_no << "even" << endl;

    }else {
        cout << std_no << " odd";
    }

    int remainder = std_no / 7;
    int multiple = std_no * 3;

    cout << "Student std_no :" << std_no << "\n" << endl;
    cout << "Digit Sum :" << sum << "\n" << endl;
    if (std_no % 2 ==0 ) {
        cout << "Odd / Even: " << "Even\n" << endl;

    }else {
        cout << "Odd / Even: " << "Odd\n" << endl;
    }

    cout << "Remainder (% 7): " << remainder << "\n" << endl;
    cout << "Multiplied by 3 : " << multiple << "\n" << endl;


}