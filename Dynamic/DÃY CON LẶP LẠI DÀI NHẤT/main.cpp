#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;
        int A[105][105] = {0};
        for (int i = 1 ; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == s[j-1] && i != j) {
                    A[i][j] = A[i-1][j-1] +1;
                } else {
                    A[i][j] = max(A[i-1][j], A[i][j-1]);
                }
            }
        }
        cout << A[n][n] << endl;
    }
    return 0;
}