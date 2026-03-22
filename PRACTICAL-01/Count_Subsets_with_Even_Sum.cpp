#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;

int main() {
    int N = 3;
    int elements[] = {1, 2, 3};
    int evenSumCount = 0;

    // total subsets = 2^N (for N=3, this is 8)
    int totalSubsets = pow(2, N);

    // loop through every possible subset (0 to 7)
    for (int i = 0; i < totalSubsets; i++) {
        int currentSum = 0;

        // build the subset and calculate its sum
        for (int j = 0; j < N; j++) {
            // bheck if the j-th element is included in subset 'i'
            if ((i & (1 << j)) != 0) {
                currentSum += elements[j];
            }
        }

        // check if the sum is even
        if (currentSum % 2 == 0) {
            evenSumCount++;
        }
    }

    cout << "Number of subsets with even sum: " << evenSumCount << endl;

    return 0;
}
