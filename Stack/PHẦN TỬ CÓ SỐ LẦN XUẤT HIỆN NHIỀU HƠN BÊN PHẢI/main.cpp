#include <bits/stdc++.h>
using namespace std;

struct Data {
    int num;
    int count;
};
/*
-1 -1 1 2 2 1 -1    
*/
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n+5],B[n+5];
        Data res[n+5];
        stack <Data> st;
        map <int,int> mp;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
            mp[A[i]]++;
            res[i].num = A[i];
            res[i].count = mp[A[i]];
        }
        for (int i = 1; i <= n; i++) {
            res[i].num = A[i];
            res[i].count = mp[A[i]];
        }
        memset(B,-1,sizeof(B));
        st.push(res[n]);
        for (int i = n-1 ; i >= 1; i--) {
            while(!st.empty() && mp[A[i]] >= st.top().count) {
                st.pop();
            }
            if (!st.empty()) {
                B[i] = st.top().num;
            }
            st.push(res[i]);
        }
        for (int i = 1; i <= n; i++) {
            cout << B[i] << " ";
        }
        cout << endl;
    }
    return 0;
}