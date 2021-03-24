#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int BFS(int u, vector < vector<int> > list, bool B[1005], int n) {
    queue <int> q;
    q.push(u);
    B[u] = true;
    int count = 0;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        count++;
        for (int i = 0; i< list[v].size(); i++) {
            if (!B[list[v][i]]) {
                q.push(list[v][i]);
                B[list[v][i]] = true;
            }
        }
    }    
    return count;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int e,v;
        cin >> v >> e;
        vector < vector<int> > list(v+5);
        bool B[1005] = {false};
        for (int i = 1; i <= e; i++) {
            int d,c;
            cin >> d >> c;
            list[d].push_back(c);
            list[c].push_back(d);
        }
        int res = 0;
        for (int i = 1; i <= v; i++) {
            if (!B[i]) {
                res++;
                BFS(i,list,B,v);
            }
        }
        cout << res <<endl;
    }
    return 0;
}