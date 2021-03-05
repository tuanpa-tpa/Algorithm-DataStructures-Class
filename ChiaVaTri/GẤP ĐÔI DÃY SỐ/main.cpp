#include <bits/stdc++.h>
using namespace std;

long long mu(long long a, long long b) {
    if (b == 1) return a;
    long long temp = mu(a, b/2);
    if (b % 2 == 0) return (temp*temp);
    return (temp*temp)*a;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n,k;
        cin >> n >> k;
        long long length = mu(2,n)/2; 
        while(true) {
            if (n == 1) {
                cout << "1";
                break;
            }
            if (k == length) {
                cout << n;
                break;
            }
            if (k > length) {
                k = length - (k-length); // xét lại k;
            }
            n--; // xét tiếp
            length/=2; // chia đổi độ dài để xét tiếp n
        }
        cout << length << endl;
    }
    return 0;
}