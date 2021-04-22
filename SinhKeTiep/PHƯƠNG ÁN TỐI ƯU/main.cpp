#include <bits/stdc++.h>

using namespace std;

bool check[105] = {
    0
};
int C[105];
int A[105];
int store[105];
int n, w;
int res = 0;
void sinh(int i) {
    for (int j = 0; j <= 1; j++) {
        check[i] = j;
        if (i == n) {
            int sum = 0;
            int temp = 0;
            for (int k = 1; k <= n; k++) {
                if (check[k]) {
                    sum += A[k];
                    temp += C[k];
                }
            }
            if (sum <= w) {
                if (res < temp) {
                    res = temp;
                    for (int k = 1; k <= n; k++) {
                        store[k] = check[k];
                    }
                }
            }
        } else {
            sinh(i + 1);
        }
    }
}


int main() {

    cin >> n >> w;
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    sinh(1);
    cout << res << endl;
    for (int i = 1; i <= n; i++) {
        cout << store[i] << " ";
    }

    return 0;
}