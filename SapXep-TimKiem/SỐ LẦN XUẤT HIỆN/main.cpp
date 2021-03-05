#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        map <int ,int> m;
        for (int i = 0; i< n; i++) {
            int temp;
            cin >> temp;
            m[temp] ++;
        }
        if (m[k]) {
            cout << m[k];
        } else {
            cout << "-1";
        }
        cout << endl;
    }
    return 0;
}