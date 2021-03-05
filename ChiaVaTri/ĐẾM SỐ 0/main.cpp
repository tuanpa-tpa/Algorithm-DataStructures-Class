#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        // vector<int> A(n);
        int d[5] = {0};
        for (int i = 0; i<n; i++) {
            int temp;
            cin >> temp;
            d[temp]++;    
        }
        cout << d[0];
        cout << endl;
    }
    return 0;
}