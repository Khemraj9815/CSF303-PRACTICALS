#include <iostream>
#include <vector>
#include <cmath> // For pow()

using namespace std;

int main() {
    int N = 3;
    int elements[] = {1, 2, 3};

    // total subsets = 2^N
    int totalSubsets = pow(2, N);

    // loop from 0 to 2^N - 1
    for (int i = 0; i < totalSubsets; i++) {
        cout << "{ ";
        
        // check each bit of the number 'i'
        for (int j = 0; j < N; j++) {
            // if the j-th bit is "on" (1), include elements[j]
            if ((i & (1 << j)) != 0) {
                cout << elements[j] << " ";
            }
        }
        
        cout << "}" << endl;
    }

    return 0;
}
