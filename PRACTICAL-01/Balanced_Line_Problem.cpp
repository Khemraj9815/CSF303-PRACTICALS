#include <iostream>
#include <deque>
#include <string>

using namespace std;

void printLine(deque<int> dq) {
    if (dq.empty()) {
        cout << "Line is empty" << endl;
        return;
    }
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    deque<int> line;
    string op;
    int x;

    cout << "enter operations (push_front, push_back, pop_front, pop_back). Type 'exit' to stop." << endl;

    while (cin >> op && op != "exit") {
        if (op == "push_front") {
            cin >> x;
            line.push_front(x);
        } 
        else if (op == "push_back") {
            cin >> x;
            line.push_back(x);
        } 
        else if (op == "pop_front") {
            if (!line.empty()) {
                line.pop_front();
            } else {
                cout << "Error: Line is already empty!" << endl;
            }
        } 
        else if (op == "pop_back") {
            if (!line.empty()) {
                line.pop_back();
            } else {
                cout << "Error: Line is already empty!" << endl;
            }
        }
        printLine(line);
    }

    return 0;
}
