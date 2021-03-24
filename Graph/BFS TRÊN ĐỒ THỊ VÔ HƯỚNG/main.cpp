#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void DFS(int u, vector < vector<int> > list, bool B[1005], int n) {
    queue <int> q;
    q.push(u);
    B[u] = true;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << " " ;
        for (int i = 0; i< list[v].size(); i++) {
            if (!B[list[v][i]]) {
                q.push(list[v][i]);
                B[list[v][i]] = true;
            }
        }
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