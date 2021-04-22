#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        long long A[100][100] = {0};
        for (int i = 1; i <= n; i++) {
            A[i][0] = 1;
        }
        for (int j = 1; j <= m; j++) {
            A[0][j] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j<= m; j++) {
                A[i][j] = A[i-1][j] + A[i][j-1];
            }
        }
        cout << A[n][m] << endl;
    }
    return 0;
}