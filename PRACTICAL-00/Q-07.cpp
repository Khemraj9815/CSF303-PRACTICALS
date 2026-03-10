#include <iostream>
#include <string>
#include <cctype> 
#include <algorithm> 
#include <iomanip>
using namespace std;

void Find_Max_Min_A(int khem[], int size, int &max, int &min, double &average){
    max = khem[0];
    min = khem[0];
    double sum = 0;

    for (int i = 0; i < size; i++) {
        if (khem[i] > max) max = khem[i];
        if (khem[i] < min) min = khem[i];
        sum += khem[i];
    }
    average = sum / size;

}

int main(){

    cout << "Student: Khem Raj Ghalley | No: 2230286" << endl;
    cout << "------------------------------------------" << endl;
    int khem[5] = {86, 76, 88, 74, 83};
    int length = sizeof(khem)/sizeof(khem[0]);
    int highest, lowest;
    double average;

    cout << "Index   " << "Mark   " << "Bar" << endl;
    for (int i = 0; i < length; i++){
        string asterisks(khem[i] / 10, '*'); 
        cout << "[" << i <<  "]" << "     " << khem[i] << "    " << asterisks << endl;

    }
    Find_Max_Min_A(khem, length, highest, lowest, average);

    int aboveCount = 0;
    for (int i = 0; i < length; i++) {
        if (khem[i] > average) aboveCount++;
    }

    cout << "------------------------------------------" << endl;
    cout << "Highest : " << highest << endl;
    cout << "Lowest  : " << lowest << endl;
    cout << "Average : " << fixed << setprecision(2) << average << endl;
    cout << "Above Average: " << aboveCount << " mark(s)" << endl;



    return 0;
}