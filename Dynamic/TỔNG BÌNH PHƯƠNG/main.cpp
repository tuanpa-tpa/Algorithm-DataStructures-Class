#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n+5];
        for (int i = 0; i <= n; i++) {
            A[i] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= sqrt(i); j++) {
                A[i] = min(A[i], A[i-j*j] + 1);
                // VD i = i - j^2 + j^2 => chỉ cẩn cộng thêm j^2
            }
        }
        cout << A[n] << endl;
    }
    return 0;
}