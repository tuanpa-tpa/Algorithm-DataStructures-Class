#include <iostream>

#include <string>

using namespace std;

int lps(string s) {
    int n = s.size();
    int A[n][n];
    for (int i = 0; i < n; i++)
        A[i][i] = 1;
    for (int k = 2; k <= n; k++) {
        for (int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1;
            if (s[i] == s[j] && k == 2)
                A[i][j] = 2;
            else if (s[i] == s[j])
                A[i][j] = A[i + 1][j - 1] + 2;
            else
                A[i][j] = max(A[i][j - 1], A[i + 1][j]);
        }
    }
    return A[0][n - 1];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << s.size() - lps(s) << endl;
    }
    return 0;
}