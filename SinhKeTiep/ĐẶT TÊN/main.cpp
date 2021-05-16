#include <bits/stdc++.h>
using namespace std;
int n,k;
int A[50];
void print() {
    for (int i = 1; i <= k; i++) {
        cout << char(A[i] + 'A' -1);
    }
    cout << endl;
}

void Try(int i) {
    for (int j = A[i-1] + 1; j <= n-k+i; j++) {
        A[i] = j;
        if (i == k) {
            print();
        } else {
            Try(i+1);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        Try(1);
    }
    return 0;
}