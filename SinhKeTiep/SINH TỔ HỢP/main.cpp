#include <iostream>
using namespace std;
int n,k;
int A[25];
bool check;
void xuat() {
    for (int i = 1; i <= k; i++) {
        cout << A[i];
    }
    cout << " ";
}
void sinh() {
    int i = k;
    while (A[i] == n-k+i) i--;
    if (i > 0) {
        A[i] ++;
        for (int j = i+1; j <=k ;j++) {
            A[j] = A[j-1]+1;
        }
    } else {
        check = false;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= k; i++) {
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