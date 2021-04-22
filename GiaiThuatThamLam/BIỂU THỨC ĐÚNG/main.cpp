#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        stack<char> st;
        string s;
        cin >> s;
        int length = s.size();
        int res = 0, del = 0;
        for (int i = 0; i < length; i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else if( st.top() == '[' && s[i] == ']') {
                del += 2;
                st.pop();
            } else if( st.top() == ']' && s[i] == '[') {
                res += del + st.size();
                st.pop();
            } else if ( 
                s[i] == '[' || 
                (st.top() == ']' && s[i] == ']') ) {
                st.push(s[i]);
            }
            if (st.empty()) del = 0;
        }
        cout << res << endl;
    }
    return 0;
}