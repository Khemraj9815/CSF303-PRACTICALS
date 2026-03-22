#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void printKMax(Array, N, K):
    Create an empty Deque (DQ) to store indices
    deque<int> q;

    for (int i=0; i<N; i++)
        // remove indices that are outside the current window
        // If DQ is not empty AND DQ.front == i - K:
        //     Remove from front of DQ
        if (!q.empty() && q.front() == i - K) {
            q.pop_front();
        }
        
        while
        // remove all elements smaller than the current element
        while (!q.empty() && Array[q.back()] <= Array[i]) {
            q.pop_back();
        }

        // add current element's index to the back
        q.push_back(i);

        // the front of the DQ is always the maximum for the window
        // start printing once the first window is fully processed
        if (i >= K - 1) {
            cout << Array[q.front()] << " ";
        }   
