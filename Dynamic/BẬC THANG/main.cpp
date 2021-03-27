#include <iostream>
#include <algorithm>
using namespace std;
const long P = 1e9+7;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        int A[100005] = {0};
        A[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i,k); j++) {
                A[i] = (A[i] + A[i-j])%P;
            }
        }
        cout << A[n] << endl;
    }
    return 0;
}