#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n,m;
        cin >> n >> m;
        long long A[n];
        long long B[m];
        for (int i = 0; i< n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i< m; i++) {
            cin >> B[i];
        }
        sort(A,A+n,greater<long long>()); // lận tý haha
        sort(B,B+m);
        long long res = A[0] * B[0];
        cout <<  res << endl;
    }
    return 0;
}