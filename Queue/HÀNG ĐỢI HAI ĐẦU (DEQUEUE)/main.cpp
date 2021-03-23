#include <iostream>
#include <deque>
using namespace std;
int main() {
    int n;
    cin >> n;
    deque <int> q;
    for (int i = 1; i <= n; i++) {
        string test;
        cin >> test;
        if (test == "PUSHFRONT") {
            int digit;
            cin >> digit;
            q.push_front(digit);
        } else if (test == "PRINTFRONT") {
             if (!q.empty()) {
                cout << q.front();
            } else {
                cout << "NONE";
            }
            cout << endl;
        } else if (test == "POPFRONT") {
            if (!q.empty()) {
                q.pop_front();
            }
        } 

        if (test == "PUSHBACK") {
            int digit;
            cin >> digit;
            q.push_back(digit);
        } else if (test == "PRINTBACK") {
             if (!q.empty()) {
                cout << q.back();
            } else {
                cout << "NONE";
            }
            cout << endl;
        } else if (test == "POPBACK") {
            if (!q.empty()) {
                q.pop_back();
            }
        } 
    }
    return 0;
}