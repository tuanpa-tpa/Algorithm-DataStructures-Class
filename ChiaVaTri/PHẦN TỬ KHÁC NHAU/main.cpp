#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        vector<int> B(n-1);
        for (int i = 0; i<n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i<n-1; i++) {
            cin >> B[i];
        }
        int i = 0;
        while(A[i] == B[i]) i++;
        cout << ++i;
        cout << endl;
    }
    return 0;
}