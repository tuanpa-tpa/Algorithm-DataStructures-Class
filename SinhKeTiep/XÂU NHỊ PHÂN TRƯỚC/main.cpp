#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size()-1;
        int i = n;
        while(s[i] == '0') {
            s[i--] = '1';
        }
        if (i >= 0) {
            s[i] = '0';
        }
        for (int i = 0; i <= n; i++) {
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}