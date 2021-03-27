#include <iostream>
#include <algorithm>
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
                B[i][j] = A[i][j];
            }
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (A[i][j] == 0) continue;{
                    if (A[i][j] == A[i-1][j] && A[i][j] == A[i][j-1] && A[i][j] == A[i-1][j-1]) {
                        int temp = min(B[i-1][j],B[i][j-1]);
                        B[i][j] = min(temp,B[i-1][j-1]) + 1;
                        res = max(res,B[i][j]);
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}