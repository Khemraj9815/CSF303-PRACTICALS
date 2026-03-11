#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

    vector<int> new_vector = {1, 2, 3, 4, 5};

    // iterating the vector in reverse order
    for (auto i = new_vector.rbegin(); i != new_vector.rend(); i++)
        cout << *i << " ";
    return 0;
}

