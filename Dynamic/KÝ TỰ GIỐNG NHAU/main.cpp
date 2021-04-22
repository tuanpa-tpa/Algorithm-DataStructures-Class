#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, ins, cpy, del;
        cin >> n >> ins >> del >> cpy;
        int A[1000] = {0}; // thời gian tối thiểu
        A[1] = ins;
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0) {
                A[i] = min(A[i-1] + ins, A[i/2] + cpy);
            } else {
                A[i] = min(A[i-1] + ins, A[i/2+1] + cpy + del);
            }
        }
        cout << A[n] << endl;
    }
    return 0;
}