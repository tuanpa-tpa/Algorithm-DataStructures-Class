#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int len(string s1, string s2) {
    int A[1005][1005] = {0};
    s1 = "0" + s1;
    s2 = "0" + s2;
    int n1 = s1.size();
    int n2 = s2.size();
    int res = 0;
    for (int i = 1; i < n1; i++) {
        for (int j = 1; j < n2; j++) {
            if (s1[i] == s2[j]) {
                A[i][j] = A[i-1][j-1] +1;
            } else {
                A[i][j] = max(A[i-1][j], A[i][j-1]);
            }
            res = max(A[i][j], res);
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        string temp = s;
        reverse(s.begin(),s.end());
        cout << s.size() - len(s,temp) << endl;
    }
    return 0;
}