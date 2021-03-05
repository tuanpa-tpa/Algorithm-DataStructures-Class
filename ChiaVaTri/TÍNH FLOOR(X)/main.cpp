#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        vector<long long> A(n);
        for (int i = 0; i<n; i++) {
            cin >> A[i];
        }
        int i = 0;
        while(A[i] <= k) i++;
        if (i == 0) cout << "-1";
        else cout << i;
        cout << endl;
    }
    return 0;
}