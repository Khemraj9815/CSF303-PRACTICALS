#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to preprocess the string
// Converts "aba" to "^#a#b#a#$" to handle even and odd length palindromes easily
string preProcess(const string& s) {
    if (s.empty()) return "^$";
    string ret = "^";
    for (char c : s) {
        ret += "#" + string(1, c);
    }
    ret += "#$";
    return ret;
}

// Function to find the longest palindromic substring using Manacher's Algorithm
string longestPalindrome(string s) {
    string T = preProcess(s);
    int n = T.length();
    
    // P array stores the radius of the longest palindrome around center i
    vector<int> P(n, 0); 
    int C = 0; // Center of the current longest palindrome
    int R = 0; // Right boundary of the current longest palindrome
    
    for (int i = 1; i < n - 1; i++) {
        // Find the mirror position of i around center C
        int i_mirror = 2 * C - i;
        
        // If i is within the right boundary, copy the mirror's value (or distance to R)
        if (R > i) {
            P[i] = min(R - i, P[i_mirror]);
        }
        
        // Expand the palindrome centered at i
        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            P[i]++;
        }
        
        // If the expanded palindrome reaches past R, update C and R
        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }
    
    // Find the maximum element in P to get the longest palindrome
    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }
    
    // Extract the actual longest palindrome from the original string
    int start = (centerIndex - 1 - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string test1 = "babad";
    string test2 = "cbbd";
    string test3 = "a";
    string test4 = "racercar";
    
    cout << "=== Manacher's Algorithm ===" << endl;
    cout << "Longest palindrome in '" << test1 << "': " << longestPalindrome(test1) << endl;
    cout << "Longest palindrome in '" << test2 << "': " << longestPalindrome(test2) << endl;
    cout << "Longest palindrome in '" << test3 << "': " << longestPalindrome(test3) << endl;
    cout << "Longest palindrome in '" << test4 << "': " << longestPalindrome(test4) << endl;

    return 0;
}