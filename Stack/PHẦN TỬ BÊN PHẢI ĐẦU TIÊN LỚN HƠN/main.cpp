#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, temp;
        cin >> n;
        int A[n+5];
        int B[n+5];
        stack <int> st;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        for (int i = n; i>= 1; i--) {
            while(!st.empty() && A[i] >= st.top()) {
                st.pop();
            }
            if (!st.empty()) {
                B[i] = st.top();
            } else {
                B[i] = -1;
            }
            st.push(A[i]);
        }
        for (int i = 1; i <= n; i++) {
            cout << B[i] << " ";
        }
        cout << endl;
    }
    return 0;
}