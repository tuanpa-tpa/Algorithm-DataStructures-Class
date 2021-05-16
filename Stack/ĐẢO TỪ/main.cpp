#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s,token;
        getline(cin >> ws,s);
        stringstream ss(s);
        stack <string> st;
        while(ss >> token) {
            st.push(token);
        }
        while(!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
    return 0;
}