#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[10005];
        int B[10005] = {0};
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        } 
        int count = 0;
        for (int i = 1; i <= n; i++) {
            B[i] = 1;
            for (int j = 1; j < i; j++) {
                if (A[i] >= A[j]) {
                    B[i] = max(B[j]+1,B[i]);
                }
            }
            count = max(count, B[i]);
        }
        cout << n - count << endl;
    }
    return 0;
}