#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    sort(A,A+n);
    long req1 = max(A[0]*A[1],A[n-1]*A[n-2]);
    long req2 = max(A[0]*A[1]*A[n-1],A[n-1]*A[n-2]*A[n-3]);
    cout << max(req1,req2);
    return 0;
}