#include <bits/stdc++.h>
using namespace std;
long long A[100];
int binaryString(long long n, long long k) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    if (k <= A[n-2]) return binaryString(n-2,k);
    return binaryString(n-1,k-A[n-2]);
}
int main() {
    A[1] = 1; A[2] = 1;
    for (int i = 3; i<= 93; i++) {
        A[i] = A[i-1] + A[i-2];
    }
    int t;
    cin >> t;
    while(t--) {
        long long n,k;
        cin >> n >> k;
        cout << binaryString(n,k) << endl;
    }
    return 0;
}