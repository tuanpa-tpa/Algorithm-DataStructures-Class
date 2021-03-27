#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[1005];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        } 
        int store[1005] = {0};
        int res = 0;
        store[0] = A[0];
        bool check = false;
        for (int i = 1; i < n; i++) {
            store[i] = A[i];
            for (int j = 0; j < i; j++) {
                if (A[i] > A[j] && (store[j] + A[i]) > store[i]) {
                    check = true;
                    store[i] = store[j]+A[i];
                    res = max(res,store[i]);
                }
            }
        }
        if (!check) cout << A[0];
        else cout << res;
        cout << endl;
    }
    return 0;
}