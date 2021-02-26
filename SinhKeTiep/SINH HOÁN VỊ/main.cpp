#include <iostream>
#include <algorithm>
using namespace std;
// 123
int n;
int A[25];
bool check;
void xuat() {
    for (int i = 1; i <= n; i++) {
        cout << A[i];
    }
    cout << " ";
}
void sinh() {
    int i = n-1;
    while (A[i] > A[i+1]) i--;
    if (i > 0) {
        int j = n;
        while (A[i] > A[j]) j--;
        swap(A[i], A[j]);
        int d = i+1, c = n;
        while(d < c) {
            swap(A[d],A[c]);
            d++;c--;
        }
    } else {
        check = false;
    }
}

int main() {
    int t;
    t = 1;
    cin >> t;
    while (t--) {
        cin >> n;
        // n = 3;
        for (int i = 1; i <= n; i++) {
            A[i] = i;
        }
        check = true;
        while(check) {
            xuat();
            sinh();
        }
        cout << endl;
    }
    return 0;
}