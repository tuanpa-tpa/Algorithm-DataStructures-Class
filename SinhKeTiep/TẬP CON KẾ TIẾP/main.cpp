#include <iostream>
using namespace std;
int n,k;
int A[10005];
void xuat() {
    for (int i = 1; i <= k; i++) {
        cout << A[i] << " ";
    }
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
        for (int j = 1; j <= k; j++) {
            A[j] = j;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= k; i++) {
            cin >> A[i];
        }
        sinh();
        xuat();
        cout << endl;
    }
    return 0;
}