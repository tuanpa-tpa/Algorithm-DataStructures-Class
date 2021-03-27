#include <iostream>
using namespace std;
const long P = 1e9+7;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if (k > n) cout << "0";
        else {
            long long res =1;
            for (int i = 0; i <= k-1; i++) {
                res = res*(n-i)%P;
            }
            cout << res;
        }
        cout << endl;
    }
    return 0;
}