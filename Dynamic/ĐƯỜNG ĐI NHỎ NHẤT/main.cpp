#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        int A[1005][1005];
        int B[1005][1005] = {0};
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> A[i][j];
            }
        }
        B[1][1] = A[1][1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i == 1) {
                    B[i][j] = B[i][j-1] + A[i][j];
                } else 
                if (j == 1) {
                    B[i][j] = B[i-1][j] + A[i][j];
                } else {
                    int temp = min(B[i-1][j],B[i][j-1]);
                    B[i][j] = min(temp,B[i-1][j-1]) + A[i][j];
                }
            }
        }
        cout << B[n][m] << endl;
    }
    return 0;
}