#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long A[105] = {0};
        A[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i,3); j++) {
                A[i] = A[i] + A[i-j]; 
            }
        }
        cout << A[n] << endl;
    }
    return 0;
}