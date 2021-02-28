#include <iostream>
using namespace std;
/*

5
1 2 3 4 5
[1 2 3 4 5] 
[3 5 7 9]
[8 12 16]
[20 28]
[48]
=> dùng mảng 2 chiều -> hàng sau sẽ bằng tổng 2 phần tử hàng trước
*/
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n+1][n+1];
        for (int i = 1; i<= n; i++) {
            cin >> A[1][i];
        }
        int cot = n-1;
        for (int i = 2; i<= n; i++) {
            for (int j = 1; j<= cot; j++) {
                A[i][j] = A[i-1][j] + A[i-1][j+1];
            }
            cot--;
        }
        cot = n;
        for (int i = 1; i<= n; i++) {
                cout << "[";
            for (int j = 1; j<= cot-1; j++) {
                cout << A[i][j] << " ";
            }
            cout << A[i][cot--] << "]" << endl;
        }
    }
    return 0;
}