#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[1000005];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        } 
        int B[1000005] = {0};
        B[1] = A[0];
        B[2] = max(A[0],A[1]);
        for (int i = 3; i <= n; i++) {
            B[i] = max(B[i-2]+A[i-1], B[i-1]);
        }
        cout << B[n] << endl;
    }
    return 0;
}