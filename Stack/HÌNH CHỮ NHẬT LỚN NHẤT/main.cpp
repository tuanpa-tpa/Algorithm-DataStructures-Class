#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int A[100005];
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        long long res = 0;
        stack <int> st;
        int i = 0;
        while(i < n) {
            if (st.empty() || A[st.top()] <= A[i]) {
                st.push(i++);
            } else {
                int tp = st.top();
                st.pop();
                long long temp = A[tp] * (st.empty() ? i : i - st.top() - 1);
                res = max(res, temp);
            }
        }
        while(!st.empty()) {
            int tp = st.top();
            st.pop();
            long long temp = A[tp] * (st.empty() ? i : i - st.top() - 1);
            res = max(res, temp);
        }
        cout << res << endl;
    }
    return 0;
}