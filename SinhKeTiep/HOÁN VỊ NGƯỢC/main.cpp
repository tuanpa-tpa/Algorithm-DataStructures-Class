#include <iostream>
using namespace std;

/* 321 312
 213
 231 213 132 123
*/
int n;
int A[25];
bool check;
void sinh() {
    int i = n-1;
    while(A[i] < A[i+1]) i--;
    if (i > 0) {
        int j = n;
        while(A[i] < A[j]) j--;
        swap(A[i], A[j]);
        int d = i+1, c = n;
        while(d < c) {
            swap(A[d],A[c]);
            d++;
            c--;
        }
    } else {
        check = false;
    }
}
void xuat() {
    for (int i = 1; i<= n; i++) {
        cout << A[i];
    }
    cout << " ";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 1; i<= n; i++) {
            A[i] = n-i+1;
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