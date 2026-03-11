#include <iostream>
#include <vector>
#include <string>
#include <iomanip> 
using namespace std;

class Student {
private:
    string name;
    int studentNumber;
    vector<float> marks;

public:
    Student(string n, int sn) {
        name = n;
        studentNumber = sn;
    }

    void addMark(float m) {
        marks.push_back(m);
    }

    float getAverage() {
        if (marks.empty()) return 0;
        float sum = 0;
        for (float m : marks) sum += m;
        return sum / marks.size();
    }

    float getHighest() {
        if (marks.empty()) return 0;
        float high = marks[0];
        for (float m : marks) if (m > high) high = m;
        return high;
    }

    float getLowest() {
        if (marks.empty()) return 0;
        float low = marks[0];
        for (float m : marks) if (m < low) low = m;
        return low;
    }

    void printReport() {
        cout << "================================================" << endl;
        cout << "ACADEMIC REPORT" << endl;
        cout << "================================================" << endl;
        cout << "Student Name: " << name << endl;
        cout << "Student No: " << studentNumber << endl;
        cout << "Marks Entered : " << marks.size() << endl;
        
        cout << "Marks: ";
        for (float m : marks) {
            cout << m << " "; // Print marks on one line
        }
        cout << endl;

        float avg = getAverage();
        cout << fixed << setprecision(2); 
        cout << "Average: " << avg << endl;
        
        cout << setprecision(0); // Remove decimals for High/Low
        cout << "Highest: " << getHighest() << endl;
        cout << "Lowest: " << getLowest() << endl;

        cout << endl; // Blank line before classification
        if (avg >= 85) cout << "Classification: Distinction" << endl;
        else if (avg >= 75) cout << "Classification: Merit" << endl;
        else if (avg >= 50) cout << "Classification: Pass" << endl;
        else cout << "Classification: Fail" << endl;
        
        cout << "================================================" << endl;
    }
};

int main() {
    // Instantiate with your details
    Student myStudent("Khem Raj Ghalley", 2230286);

    myStudent.addMark(80);
    myStudent.addMark(66);
    myStudent.addMark(81);
    myStudent.addMark(68);
    myStudent.addMark(88);

    myStudent.printReport();

    return 0;
}
