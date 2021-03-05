#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k,m;
        cin >> n >> m >> k;
        vector<int> A(n+m);
        for (int i = 0; i<n+m; i++) {
            cin >> A[i];
        }
        sort(A.begin(),A.end());
        cout << A[k-1];
        cout << endl;
    }
    return 0;
}