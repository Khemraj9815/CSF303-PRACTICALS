#include <iostream>
#include <string>

using namespace std;

// sum of digit
int digitSum(int n) {
    int sum = 0;
    if (n < 0) n = -n; 
    while (n > 0) {
        sum = sum + (n % 10);
        n = n / 10;
    }
    return sum;
}

// function to check prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false; 
    }
    return true;
}

// function to count vowels
int countVowels(string s) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
    
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
    }
    return count;
}

// reverse string
string reverseString(string s) {
    string reversed = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        reversed = reversed + s[i]; 
    }
    return reversed;
}

int main() {
    string fullName = "Khem Raj Ghalley"; // Replace with your actual name
    int studentNo = 2230386;

   
    cout << "========================================" << endl;
    cout << "Function Results for " << fullName << endl;
    cout << "Student No: " << studentNo << endl;
    cout << "========================================" << endl;

    cout << "digitSum(" << studentNo << "): " << digitSum(studentNo) << endl;
    
    cout << "isPrime(" << studentNo << "): ";
      if (isPrime(studentNo)) cout << "Yes" << endl;
    else cout << "No" << endl;

    cout << "countVowels(" << fullName << "): " << countVowels(fullName) << endl;
    
    cout << "reverseString(" << fullName << "): " << reverseString(fullName) << endl;
    
    cout << "========================================" << endl;

    return 0;
}
