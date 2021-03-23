#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    // t = 1;
    while(t--) {
        int A[1005][1005] = {0};
        string s1,s2;
        cin >> s1 >> s2;
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
        cout << res << endl;  
    } 
    return 0;
}