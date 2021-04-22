#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s1, s2;
        cin >> s1 >> s2;
        int length1 = s1.size();
        int length2 = s2.size();
        int A[length1+6][length2+6]; // cách biến i s1 thành j s2
        for (int i = 0; i <= length1; i++) {
            for (int j = 0; j <= length2; j++) {
                if (i == 0 || j == 0) {
                    A[i][j] = i+j;
                } else if(s1[i-1] == s2[j-1]) {
                    A[i][j] = A[i-1][j-1];
                } else {
                    A[i][j] = 1 + min(A[i][j-1],min(A[i-1][j],A[i-1][j-1])); // ins, del, remo
                }
            }
        }
        cout << A[length1][length2] << endl;
    }
    return 0;
}