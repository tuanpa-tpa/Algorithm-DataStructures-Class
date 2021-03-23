#include <iostream>
#include <queue>
using namespace std;
int main() {
    int n;
    cin >> n;
    queue <int> q;
    for (int i = 1; i <= n; i++) {
        string test;
        cin >> test;
        if (test == "PUSH") {
            int digit;
            cin >> digit;
            q.push(digit);
        } else if (test == "PRINTFRONT") {
             if (!q.empty()) {
                cout << q.front();
            } else {
                cout << "NONE";
            }
            cout << endl;
        } else if (test == "POP") {
            if (!q.empty()) {
                q.pop();
            }
        } 
    }
    return 0;
}