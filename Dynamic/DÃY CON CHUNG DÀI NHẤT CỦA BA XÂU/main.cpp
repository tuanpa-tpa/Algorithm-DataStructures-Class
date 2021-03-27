#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int xauChung(string s1, string s2, string s3, int x, int y, int z) {
    int A[105][105][105] = {0};
    for (int i = 1; i <= x; i++) {
        for (int j = 1; j<= y; j++) {
            for (int k = 1; k <= z; k++) {
                if (s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) {
                    A[i][j][k] = A[i-1][j-1][k-1] + 1;
                } else {
                    int temp = max(A[i-1][j][k], A[i][j-1][k]);
                    A[i][j][k] = max(temp, A[i][j][k-1]);
                }
            }
        }
    }
    return A[x][y][z];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        string s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        cout << xauChung(s1,s2,s3,n,m,k) << endl;
    }
    return 0;
}