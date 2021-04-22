#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,
            A[105],
            req1[105],
            req2[105],
            res = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            req1[i] = A[i];
            req2[i] = A[i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < i; j++) {
                if (A[i] > A[j]) {
                    req1[i] = max(req1[i], req1[j]+A[i]); // dãy tăng
                }
            }
        }

        for (int i = n-1; i >= 1; i--) {
            for (int j = n; j > i ; j--) {
                if (A[i] > A[j]) {
                    req2[i] = max(req2[i], req2[j]+A[i]); // dãy giảm
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            res = max(res, req1[i] + req2[i] - A[i]);
        }
        cout << res << endl;
    }
    return 0;
}