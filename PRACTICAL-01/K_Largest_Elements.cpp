#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int N = 6, K = 3;
    int elements[] = {7, 10, 4, 3, 20, 15};

    // by default, priority_queue keeps the largest element at the top.
    priority_queue<int> pq;

    // Push all elements into the priority queue
    for (int i = 0; i < N; i++) {
        pq.push(elements[i]);
    }

    // printing and removing the top K elements
    cout << "The " << K << " largest elements are: ";
    for (int i = 0; i < K; i++) {
        // .top() gives us the largest current number
        cout << pq.top() << " ";
        
        // .pop() removes that largest number so we can see the next one
        pq.pop();
    }
    cout << endl;

    return 0;
}
