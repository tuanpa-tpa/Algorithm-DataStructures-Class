#include <iostream>
#include <stack>
#include <vector>
using namespace std;


void DFS(int u, vector < vector<int> > list, bool B[1005], int n) {
    stack<int> st;
    st.push(u);
    cout << u << " ";
    B[u] = true;
    while(!st.empty()) {
        int v = st.top(); st.pop();
        // for (int i = 1; i <= n; i++) {
            for (int j = 0; j < list[v].size(); j++) {
                if (!B[list[v][j]]) {
                    cout << list[v][j] << " ";
                    B[list[v][j]] = true;
                    st.push(v);
                    st.push(list[v][j]);
                    break;
                }
            }
        // }
    }
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int e,v,u;
        cin >> v >> e >> u;
        vector < vector<int> > list(v+5);
        bool B[1005] = {false};
        for (int i = 1; i <= e; i++) {
            int d,c;
            cin >> d >> c;
            list[d].push_back(c);
            list[c].push_back(d);
        }
        DFS(u,list,B,v);
        cout << endl;
    }
    return 0;
}