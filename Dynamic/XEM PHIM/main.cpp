#include <iostream>
using namespace std;

int main() {
    int c,n;
    cin >> c >> n;
    int A[n+5];
    for (int i = 1; i<= n; i++) {
        cin >> A[i];
    }
    int B[105][25005] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= c; j++) {
            if (j < A[i]) {
                B[i][j] = B[i-1][j];
            } else {
                B[i][j] = max(B[i-1][j], B[i-1][j-A[i]]+A[i]);
            }
        }
    }
    cout << B[n][c] << endl;
    return 0;
}