#include <iostream>
using namespace std;

struct wrap {
    int gt;
    int tl;
};

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,v;
        cin >> n >> v;
        wrap A[n+5];
        for (int i = 1; i<= n; i++) {
            cin >> A[i].tl;
        }
        for (int i = 1; i<= n; i++) {
            cin >> A[i].gt;
        }
        int B[1005][1005] = {0};
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j<= v; j++) {
                if (j < A[i].tl) {
                    B[i][j] = B[i-1][j];
                } else {
                    B[i][j] = max(B[i-1][j],B[i-1][j-A[i].tl]+A[i].gt);
                }
            }
        }
        cout << B[n][v] << endl;
    }
    return 0;
}