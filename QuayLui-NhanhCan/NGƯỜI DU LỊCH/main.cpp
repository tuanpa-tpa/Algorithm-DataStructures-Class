#include <iostream>
#include <algorithm>
using namespace std;
int n,sum = 0,res = 1000000;
int A[20][20];
bool check[20] = {false};
int mins = 100000;
int B[20];

void backTrack(int i) {
    for (int j = 2; j <= n; j++) {
    if (sum + mins*(n-i+1) >= res) return; // nếu số tiền đang sét cộng với số tiền nhỏ nhất đi 
    // hết n-i+1 thành phố còn lại lớn hơn thì return
        if (!check[j]) {
            check[j] = true;
            B[i] = j;
            sum += A[B[i-1]][B[i]]; // cộng với số tiền đi từ thành phố trước đó đến tp i
            if (i == n) {
                res = min(res, sum + A[B[n]][B[1]]);  // cộng với chi phí đi từ n về 1
            } else {
                backTrack(i+1);
            }
            check[j] = false;
            sum -= A[B[i-1]][B[i]];
        }
    }
}   

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
            if (A[i][j] != 0) mins = min(mins,A[i][j]);
        }
    }
    B[1] = 1;
    backTrack(2);
    cout << res;
    return 0;
}