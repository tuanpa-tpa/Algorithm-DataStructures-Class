#include <iostream>
using namespace std;
const int M = 1e9+7;
int n,k;
long long TK(int A[]) {
    long long F[1005] = {0};
    F[0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            if (A[j] <= i) {
                F[i] = (F[i] + F[i-A[j]])%M;
            }
        }
    }
    return F[k];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        int A[n+5];
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        cout << TK(A) << endl;
    }
    return 0;
}