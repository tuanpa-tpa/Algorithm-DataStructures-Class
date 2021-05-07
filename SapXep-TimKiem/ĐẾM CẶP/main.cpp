#include <bits/stdc++.h>
using namespace std;
/*
    nếu x > y thì x^y > y^x
    TH đặc biệt
      0 1 2 3 4
    0 0 0 0 0 0
    1 1 0 0 0 0
    2 1 1 0 0 0
    3 1 1 1 0 1
    4 1 1 0 0 0
*/


int req(int B[] , int m, int C[], int x) {
    if (x == 0) return 0;
    if (x == 1) return C[0];
    int temp = upper_bound(B, B + m, x) - B; // vị trí đầu tiên mà x > B[i]
    int res = m - temp; // => các phần tử đằng sau đều thỏa mãn x > y hay x^y > y^x
    res += C[0] + C[1];
    if (x == 2) res -= (C[3] + C[4]);
    if (x == 3) res += C[2];
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,m;
        long res = 0;
        cin >> n >> m;
        int A[n],B[m],C[10] = {0};
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> B[i];
            if (B[i] <= 4) { // đếm số lượng phần tử trong y <= 4 để xét
                C[B[i]]++;
            }
        }
        sort(B,B+m);
        for (int i = 0; i < n; i++) {
            res += req(B,m,C,A[i]);
        }
        cout << res << endl;
    }
    return 0;
}