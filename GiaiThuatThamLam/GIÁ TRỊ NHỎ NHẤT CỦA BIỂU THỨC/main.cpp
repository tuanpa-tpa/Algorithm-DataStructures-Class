#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long A[n],B[n];
        long long p = 1e9+7;
        for (int i = 0; i< n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i< n; i++) {
            cin >> B[i];
        }
        sort(A,A+n); // sắp xếp tăng dần
        sort(B,B+n,greater<long long>()); // sắp xếp giảm dần
        long long res = 0;
        for (int i = 0; i< n; i++) {
            res += A[i]*B[i];
            // res %= p;
        }
        cout << res << endl;
    }
    return 0;
}