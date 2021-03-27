#include <iostream>
#include <queue>
using namespace std;

/*
A[3] = 4 + 34 + 234 + 1234
           = 4 + 30 + 4 + 230 + 4 + 1230 + 4
           = 4*4 + 10*(3 + 23 +123)
           = 4*4 + 10*(A[2])
A[i]  =  (i+1)*num[i] + 10*A[i-1]
*/


int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int n = s.size();
        long long A[n+5];
        A[0] = int(s[0]-'0');
        long long res = A[0];
        for (int i = 1; i < n; i++) {
            int num = int(s[i]-'0');
            A[i] = (i+1)*num + 10*A[i-1]; // công thức được chứng minh
            res += A[i];
        }
        cout << res << endl;
    }
    return 0;
}