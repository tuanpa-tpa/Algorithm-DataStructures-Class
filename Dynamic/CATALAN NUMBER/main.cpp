#include <iostream>
using namespace std;
unsigned long long res(int n) {
    unsigned long long A[n + 1];
    A[0] = 1;
    A[1] = 1;
    for (int i = 2; i <= n; i++) {
        A[i] = 0;
        for (int j = 0; j < i; j++)
            A[i] += A[j] * A[i - j - 1];
    }
    return A[n];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << res(n);
        cout << endl;
    }
    return 0;
}