#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        pair<int, int> A [n+5];
        int res[n+5];
        for (int i = 1; i <= n; i++) {
            cin >> A[i].first >> A[i].second;
            res[i] = 1;
        }
        sort(A+1,A+n+1,cmp);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (A[i].first > A[j].second) {
                    res[i] = max(res[i], res[j] + 1);
                }
            }
        }
        cout << res[n] << endl;
    }
    return 0;
}