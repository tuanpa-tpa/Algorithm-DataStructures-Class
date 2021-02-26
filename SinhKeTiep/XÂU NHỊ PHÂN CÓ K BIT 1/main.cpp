#include <iostream>
using namespace std;

int n,k;
int A[25];
bool check;
void xuat() {
    for (int i = 1; i <= n; i++) {
        cout << A[i];
    }
    cout << endl;
}
void sinh() {
    int i = n;
    while(A[i] == 1) {
        A[i--] = 0;
    }
    if (i > 0) {
        A[i] = 1;
    } else {
        check = false;
    }
}
bool checkBit() {
    int B[3] = {0};
    for (int i = 1; i<= n; i++) {
        B[A[i]] ++;
    }
    return (B[1] == k);
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        check = true;
        while(check) {
            if (checkBit()) xuat();
            sinh();
        }
    }
    return 0;
}