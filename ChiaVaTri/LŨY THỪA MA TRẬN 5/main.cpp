#include <bits/stdc++.h>
using namespace std;
int t;
long long n ,k;
const long long M = 1e9+7;
struct Matran {
    long long M[15][15];
};
Matran operator *(Matran A, Matran B) {
    Matran C;
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j<= n; j++) {
            C.M[i][j] = 0;
            for (int k = 1; k<= n; k++) {
                C.M[i][j] = (C.M[i][j] + A.M[i][k]*B.M[k][j]%M)%M;
            }
        }
    }
    return C;
}

Matran POW(Matran A, long long k) {
    if (k == 1) return A;
    Matran temp = POW(A, k/2);
    if (k % 2 == 0) return temp*temp;
    return temp*temp*A;
}

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> k;
        Matran A;
        for (int i = 1; i<= n; i++) {
            for (int j = 1; j<=n; j++) {
                cin >> A.M[i][j];
            }
        }
        Matran res;
        res = POW(A,k);
        long long ans = 0;
        for (int i = 1; i<= n; i++) {
            ans = (ans + res.M[n][i])%M;
        }
        cout << ans << endl;
    }
    return 0;
}