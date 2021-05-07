#include <bits/stdc++.h>
using namespace std;

/*
5 1 9 2 5 1 7
      5 7 7 -1
*/

int main() {
    int t = 1;
    cin >> t;
    while(t--) {
        int n = 7;
        stack <long> st;
        cin >> n;   
        int A[n+5],B[n+5],C[n+5];
        A[0] = -1;
        for (int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        memset(B,0,sizeof(B));
        st.push(n);
        for(int i = n-1; i >= 1; i--) {
			while(!st.empty() && A[i] >= A[st.top()]) {
				st.pop();
			}
			if(!st.empty()) {
				B[i] = st.top();
            } else {
                B[i] = 0;
            }
			st.push(i);
		}
        stack <long> st2;
        memset(C,0,sizeof(C));
        st2.push(n);
        for(int i = n-1; i >= 1; i--) {
			while(!st2.empty() && A[i] <= A[st2.top()]) {
				st2.pop();
			}
			if(!st2.empty()) {
				C[i] = st2.top();
            } else {
                C[i] = 0;
            }
			st2.push(i);
		}
        for (int i = 1; i <= n; i++) {
            cout << A[C[B[i]]] << " ";
        }
        cout << endl;
    }
    return 0;
}