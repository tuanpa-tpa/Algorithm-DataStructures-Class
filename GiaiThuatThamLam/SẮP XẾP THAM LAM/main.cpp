#include <iostream>
#include <algorithm>
using namespace std;

/*
2
7
1 6 3 4 5 2 7
1 2 3 4 5 6 7
7
1 6 3 4 5 7 2
1 2 3 4 5 6 7

Yes
No
*/

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n],B[n];
        for (int i = 1; i<= n; i++) {
            cin >> A[i];
            B[i] = A[i];
        }
        sort(B+1,B+n+1);
        bool check = true;
        for (int i = 1; i <= n; i++) {
            if (A[i] != B[i] && A[i] != B[n-i+1] ){
                check = false;
                break;
            }
        }
        if (check) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}