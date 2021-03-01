#include <iostream>
#include <string>
using namespace std;

/*

*/

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        int d;
        cin >> d >> s;
        int A[200] = {0};
        int MAX = 0;
        for (int i = 0; i < s.size(); i++) {
            A[s[i]]++;
            if (A[s[i]] > MAX) {
                MAX = A[s[i]];
            }
        }
        // bool check = true;
        if ((MAX-1)*(d-1) <= s.size() - MAX) cout << "1";
        else cout << "-1";
        cout << endl;
    }
    return 0;
}