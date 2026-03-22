#include <iostream>
#include <vector>
#include <algorithm> // for sort and unique
using namespace std;

int main() {
    vector<int> vec = {1, 2, 2, 3, 4, 4, 5};

    // 1. Sort the vector (required for unique to work)
    sort(vec.begin(), vec.end());

    // 2. Use unique to move duplicates to the end
    // 3. Use erase to remove the "garbage" elements from the vector
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    // Print the result
    for (int x : vec) {
        cout << x << endl;
    }

    return 0;
}
