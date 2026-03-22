#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    vector<int> v = {1, 2, 2, 3, 4, 4, 5};

    // sort the vector to bring duplicates together
    sort(v.begin(), v.end());

    //  find the unique elements and move them to the front of the vector
    int unique = 0; 
    for (int i = 1; i < v.size(); ++i) {
        // if current element is different from the last unique one found
        if (v[i] != v[unique]) {
            unique++;
            v[unique] = v[i]; // move the unique element forward
        }
    }
    v.resize(unique + 1);

    cout << "new vector: ";
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
