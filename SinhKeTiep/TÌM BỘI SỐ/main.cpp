#include <iostream>
#include <algorithm>
using namespace std;
/*
 3 -> 90
 10 *9 = 90
 5 -> 90
 => sinh nhị phân được chuỗi 0,1 ta đem nhân với 9 để được chuỗi gồm chữ số 0,9 
 -> xét xem số đấy có chia cho n hay không -> min
*/


int n, d;
int A[200];
long long kq = 1e18;
bool check;

void xuat() {
    for (int i = 1; i<= d; i++) {
        cout << A[i];
    }
    cout << endl;
}
// cách 1 dùng quay lui
void sinh(int i) {
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == d) {
            long long temp = 0;
            for (int k = 1; k <= d; k++) {
                temp = temp * 10 + A[k];
            }
            temp *= 9;
            if (temp % n == 0 && temp >= n) {
                kq = min(temp,kq); // tìm giá trị min
                check = false;
            }
            // xuat();
        } else {
            sinh(i+1);
        }
    }
}
// cách 2 dùng sinh 


int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        kq = 1e18;
        check = true;
        d = 3;
        while (d <= 20 && check) {
            sinh(1);
            d++;
        }
        cout << kq << endl;
    }
    return 0;
}