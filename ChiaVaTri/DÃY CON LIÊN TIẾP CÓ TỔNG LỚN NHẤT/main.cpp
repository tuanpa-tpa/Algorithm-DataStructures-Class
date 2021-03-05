#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i<n; i++) {
            cin >> A[i];
        }
        int S = 0,number_max = -1e9;
        for (int i = 0; i< n; i++) {
            if (S + A[i] < 0) {
                S = 0;
            } else {
                S += A[i];
                number_max = max(number_max,S);
            }
        }
        cout << number_max;
        cout << endl;
    }
    return 0;
}