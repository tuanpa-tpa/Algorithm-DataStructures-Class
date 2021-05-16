#include <bits/stdc++.h>
using namespace std;

int n;
int A[50];
// 0 là A 1 là H

void print() {
    for (int i = 1; i <= n; i++) {
        if (A[i] == 0) cout << "A";
        else cout << "H";
    }
    cout << endl;
}

bool check() {
    if (A[1] == 0 || A[n] == 1) return false;
    for (int i = 1; i <= n-1; i++) {
        if (A[i] == 1 && A[i+1] == 1) return false;
    }
    return true;
}

void Try(int i) {
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == n) {
            if (check()) {
                print();
            }
        } else {
            Try(i+1);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        Try(1);
    }
    return 0;
}