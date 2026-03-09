#include <iostream>
#include <string>
#include <cctype> 
#include <algorithm> 
using namespace std;

int main(){
    string name;
    cout << "enter your name: ";
    cin >> name;
    int stutudent_No;
    cout << "enter your student Number: ";
    cin >> stutudent_No;
    int student_age;
    cout << "enter your age: ";
    cin >> student_age;
    // calculate the year they were born
    // take input from student birth year
    int birth_year;
    cout << "Enter your birth year: ";
    cin >> birth_year;
    int current_year = 2026;
    int age = current_year - birth_year;
    // age after 100 year
    int age_after_100_y = birth_year + 100;
    
    cout << "-------------------------------" << endl;
    cout << "           Summmary            " << endl;
    cout << "-------------------------------" << endl;

    cout << "Name           : " << name << endl;
    cout << "Student No     : " << stutudent_No << endl;
    cout << "Year of Birth  : " << birth_year << endl;
    cout << "Year at Age 100: " << age_after_100_y << endl;


}
