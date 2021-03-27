#include <bits/stdc++.h>
using namespace std;
/*
2
4
4 3 2 1
5
1 2 3 4 5    1 2 3 4 5 -> key
1 5 4 3 2 -> 1 2 4 3 5 -> 1 2 3 4 5 
1 2 3 4 5 -> sau sort -> trả lại ban đầu
=> sắp xếp tăng dần -> xét xem có thay đổi vị trí không -> nếu thay đổi -> đảo lại vị trí ban đầu và d++
2
2
*/

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n+5],B[n+5];
        for (int i = 0; i< n; i++) {
            cin >> A[i];    
            B[i] = A[i];
        }
        sort(B,B+n);

        long long res1 = 0;
        for (int i = 0; i< n; i++) {
            if (A[i] != B[i]) {
                for (int j = i+1; j < n; j++) {
                    if (A[j] == B[i]) {
                        swap(A[j],A[i]);
                        res1++;
                        break;
                    }
                }
            }
        }
        cout << res1 << endl;
    }
    return 0;
}

