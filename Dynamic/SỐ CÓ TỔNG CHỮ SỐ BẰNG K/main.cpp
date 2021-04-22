#include <iostream>
using namespace std;
int P = 1e9+7;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,k;
        cin >> n >> k;
        int A[100][1000] = {0};
        for (int i = 1; i <= 9; i++) {
            A[1][i] = 1;
        }
        for (int i = 1; i<= n ; i++) {
            for (int j = 1; j <= k; j++) {
                for (int k = 0; k<= 9; k++) {
                    if (k <= j) {
                        A[i][j] = (A[i-1][j-k] + A[i][j])%P;
                    }
                }
            }
        }
        cout << A[n][k] << endl;
    }
    return 0;
}