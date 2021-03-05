#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i<n; i++) {
            cin >> A[i];
        }
        sort(A.begin(),A.end());
        if (A[0] == A[1]) cout << "-1";
        else cout << A[0] << " " << A[1];
        cout << endl;
    }
    return 0;
}