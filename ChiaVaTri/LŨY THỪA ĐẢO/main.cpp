#include <bits/stdc++.h>
using namespace std;
long long P = 1e9+7;
long long mu(long long a, long long b) {
    if (b == 1) return a%P;
    long long temp = mu(a, b/2);
    if (b % 2 == 0) return (temp*temp)%P;
    return (temp*temp%P)*a%P;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long temp = n, r = 0;;
        while(temp) {
            long long num = temp%10;
            r = r*10 + num;
            temp /= 10;
        }
        cout << mu(n,r) << endl;
    }
    return 0;
}