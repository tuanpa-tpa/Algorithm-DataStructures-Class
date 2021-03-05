#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main() {
    string s;
    stack<int> st;
    while(cin >> s) {
        if (s == "push") {
            int n;
            cin >> n;
            st.push(n);
        } else if (s == "pop") {
            st.pop();
        } else if (s == "show"){
            vector <int> A;
            if (st.empty()) {
                cout << "empty" << endl;
                continue;
            } else {
                while(st.size() > 0) {
                    A.push_back(st.top());
                    st.pop();
                }
                for (int i = A.size()-1; i>= 0; i--) {
                    cout << A[i] << " ";
                    st.push(A[i]);
                }
                cout << endl;
            }
        } 
    }
    return 0;
}