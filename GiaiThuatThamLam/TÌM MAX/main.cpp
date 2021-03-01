#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        long long p = 1000000007;
        cin >> n;
        long long A[n];
        for (long long i = 0; i < n; i++) {
            cin >> A[i];
        }
        sort(A,A+n);
        long long sum = 0;
        for (long long i = 0; i< n; i++) {
            sum += A[i]*i;
            sum %= p;
        }
        cout << sum << endl;
    }
    return 0;
}
\