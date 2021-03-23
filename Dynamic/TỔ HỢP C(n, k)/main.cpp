#include <iostream>
using namespace std;
const long P = 1e9+7;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        long long A[1005][1005] = {0};
        // kCn = k-1Cn-1 + kCn-1
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (i == j || j == 0) {
                    A[i][j] = 1;
                } else {
                    A[i][j] = A[i-1][j-1] + A[i-1][j];
                    A[i][j] = A[i][j] % P;
                }
            } 
        }
        cout << A[n][k] << endl;
    }
    return 0;
}