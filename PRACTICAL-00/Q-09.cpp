#include <iostream>
#include <vector>
#include <algorithm> // Required for sort, min_element, and max_element
#include <numeric>   // Required for accumulate (sum)

using namespace std;

int main() {
    // vector with student number
    vector<int> v2230286;
    int input;

    // 2. Populate at runtime
    cout << "Enter 6 values: ";
    for (int i = 0; i < 6; i++) {
        cin >> input;
        v2230286.push_back(input);
    }

    cout << "-----------------------------------------" << endl;

    cout << "Original: ";
    for (int x : v2230286) {
        cout << x << " ";
    }
    cout << endl;

    // sort 
    sort(v2230286.begin(), v2230286.end());
    cout << "Sorted: ";
    for (int x : v2230286) {
        cout << x << " ";
    }
    cout << endl;

    // min, max and avg
    int minVal = *min_element(v2230286.begin(), v2230286.end());
    int maxVal = *max_element(v2230286.begin(), v2230286.end());
    int sum = accumulate(v2230286.begin(), v2230286.end(), 0);
    double average = (double)sum / v2230286.size();

    cout << "Min: " << minVal << " Max: " << maxVal << " Sum: " << sum << " Average: " << average << endl;
    cout << "-----------------------------------------" << endl;

    for (int i = 0; i < v2230286.size(); ) {
        if (v2230286[i] < average) {
            v2230286.erase(v2230286.begin() + i);
        } else {
            i++;
        }
    }

    // 7. Display final vector
    cout << "After removing below average:" << endl;
    for (int x : v2230286) {
        cout << x << endl;
    }

    return 0;
}
