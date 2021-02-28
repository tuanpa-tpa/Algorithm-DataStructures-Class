#include <iostream>
#include <algorithm>
using namespace std;
/*
1
3 5
1 4 5
 -> 1 là tờ tiền 5
=> ta chỉ cần chọn tổ hợp nCi ( 1<= i < n)
*/
int A[50];
int B[50];
int n,k;
bool check = true;
void sinh(int t) {
    int i = t;
    while (B[i] == n-t+i) i--;
    if (i >= 1) {
        B[i]++;
        for (int j = i+1; j<= t; j++) {
            B[j] = B[j-1]+1;
        }
    } else {
        check = false;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int res = 0;
        cin >> n >> k;
        for (int i = 1; i<= n; i++) {
            cin >> A[i];
        }

        for (int i = 1; i < n; i++) {
            check = true;
            for (int j = 1; j<= i; j++) { // khởi tạo tổ hợp ban đầu
                B[j] = j;
            }
            while (check) {
                int temp = 0;
                for (int j = 1; j<= i; j++) {
                    temp += A[B[j]];
                }
                if (temp == k) {
                    res = i;
                    // cout << res << "";
                    break;
                } else {
                    sinh(i);
                }
            }
            if (res) break;
        }
        if (res) {
            cout << res;
        } else {
            cout << "-1";
        }
        cout << endl;
    }
    return 0;
}