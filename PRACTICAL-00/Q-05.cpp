#include <iostream>
#include <string>
#include <cctype> 
#include <algorithm> 
using namespace std;

int main(){
    string name = "Khem Raj Ghalley";
    int stutudent_No = 2230286;
    string grade, result;

    int mark;
    cout << "enter mark between 0-100: ";
 
    cin >> mark;
    
    if (mark >= 0 && mark <= 100) {
        if (mark >= 75) {
            grade = "Distinction";
            result = "Congratulations, " + name + "! You have passed.";
        } else if (mark >= 60) {
            grade = "Merit";
            result = "Congratulations, " + name + "! You have passed.";
        }  else if (mark >= 40) {
             grade = "Pass";
            result = "Congratulations, " + name + "! You have passed.";
        } else  {
            grade = "Fail";
            result = "Sorry, " + name + ". You did not pass.";
        }

        cout << "------------------------------------------------------------" << endl;
        cout << "Student: " << name << "(" << stutudent_No << ")" << endl;
        cout << "Mark: " << mark << endl;
        cout << "Grade: " << grade << endl;
        cout << "Result : " << result << endl;
        cout << "-------------------------------------------------------------" << endl;

        
    }else {
        cout << "Invalid input!!! Please enter mark between 0-100.";
    }
    
  return 0;  
}

