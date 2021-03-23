#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,k;
int A[105];
int sum = 0;
bool check[105];
bool kt = false;
void backTrack(int s, int count) {
    if (count == k) {
        kt = true;
        return;
    } 
    if (kt) return;

    for (int i = 1; i <= n; i++) {
        if (!check[i]) {
            check[i] = true;
            if (s > sum/k) return;

            if (s + A[i] <= sum/k) { 
                // có thể để count lên này -> do test lỗi 
                backTrack(s+A[i],count);
            }

            if (s == sum/k) {
                count++;
                backTrack(0,count);
            }
        }
        check[i] = false;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        sum = 0;kt = false;
        for (int i = 1; i<= n; i++) {
            cin >> A[i];
            sum+= A[i];
            check[i] = false;
        }
        if (sum % k) {
            cout << "0";
        } else {
            backTrack(0,0);
            if (kt) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }
    return 0;
}