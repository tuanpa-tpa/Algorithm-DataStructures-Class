#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n,k;
        long P = 1e9+7;
        cin >> n >> k;
        n = n%P;
        long long res = 1;
        while(k) {
            if (k % 2 != 0) {
                res = (res*n)%P;
            }
            k/=2;
            n = (n*n)%P;
        }
        cout << res;
        cout << endl;
    }
    return 0;
}