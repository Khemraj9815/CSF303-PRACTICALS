#include <iostream>
#include <string>
#include <cctype> 
#include <algorithm> 
using namespace std;

int main () {
    // declear my name
    string name = "Khem Raj Ghalley";

    cout << "Full Name: " << name << "\n" << endl;

    // first set the count value as 0
    int count = 0;
    // iterate through string using for loop includin spaces
    for (int i=0; i < name.length(); i++ ) {
        ++count;
    }
    // transform the alphabet to upper case
    transform(name.begin(), name.end(), name.begin(), ::toupper);
    
    cout << "Total Length: " << count << "\n" << endl;
    cout << "Uppercase : " << name << "\n" << endl;
    // lower case
    transform(name.begin(), name.end(), name.begin(), ::tolower);

    cout << "Lowercase: " << name << "\n" << endl;

    // initials 
    cout << "Initials: ";
    for (int i = 0; i < name.length(); i++) {
        if (i == 0 && name[i] != ' ' ) {
            cout << (char) toupper(name[i]);

        }else if (i > 0 && name[i - 1] == ' '  && name[i] != ' '){
            cout <<  "." << (char) toupper(name[i]);
        }
        
    }
    cout << "\n" << endl;

    // length of the first word 
    int first_word_length = 0;
    for (int i =0; i < name.length(); i++) {
        if (name[i] == ' ') {
            break;
        }
        first_word_length++;
    }
 
    cout << "First Name Len: " << first_word_length << endl;

    return 0;
}