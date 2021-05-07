#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        stack<int> st;
        for (int i = 0; i <= s.length(); i++) {
            st.push(i+1);
            if (i == s.length() || s[i] == 'I') {
                while(!st.empty()) {
                    cout << st.top();
                    st.pop();
                }
            }
        }
        cout << endl;
    }
    return 0;
}