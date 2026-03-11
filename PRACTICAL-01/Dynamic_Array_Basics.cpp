#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    // first initialize vector
    vector<int> new_vector; // vector initialized
    // add element in vector
    new_vector.push_back(7);
    new_vector.push_back(6);
    new_vector.push_back(2);
    new_vector.push_back(9);

    cout << "Value at the index 1: " << new_vector[1] << endl;
    

    // loop through vector using using iteration
    for (auto i = 0; i < new_vector.size(); i++){
        // print out all the element
        cout << new_vector[i] << endl;
    }

    int Min_Value = new_vector[0];
    int Max_Value = new_vector[0];
    for (size_t i = 1; i < new_vector.size(); ++i) {
        
            if (new_vector[i] < Max_Value) {
                Min_Value = new_vector[i];
            }
            if (new_vector[i] > Max_Value) {
                Max_Value = new_vector[i];
            }
        }

    cout << "Max Value:" << Max_Value << endl;
    cout << "Min Value:" << Min_Value << endl;

    return 0;
}

