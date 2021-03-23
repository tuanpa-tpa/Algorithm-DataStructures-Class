#include <iostream>
#include <queue>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        queue <int> q;
        for (int i = 1; i <= n; i++) {
            int test;
            cin >> test;
            if (test == 1) {
                cout << q.size() << endl;
            } else if (test == 2) {
                if (q.empty()) {
                    cout << "YES";
                } else {
                    cout << "NO";
                }
                cout << endl;
            } else if (test == 3) {
                int digit;
                cin >> digit;
                q.push(digit);
            } else if (test == 4) {
                if (!q.empty()) {
                    q.pop();
                }
            } else if (test == 5) {
                if (!q.empty()) {
                    cout << q.front();
                } else {
                    cout << "-1";
                }
                cout << endl;
            } else if (test == 6) {
                if (!q.empty()) {
                    cout << q.back();
                } else {
                    cout << "-1";
                }
                cout << endl;
            }   
        }
    }
    return 0;
}