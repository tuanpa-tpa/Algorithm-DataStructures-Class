#include <bits/stdc++.h>

using namespace std;
int v,e,s;
int A[505][505];
bool check[505] = {false};
vector < vector <int> > listG(1005);
vector < pair <int, int> > res;

void Tree_BFS(int u) {
    res.clear();
    memset(check,false,sizeof(check));
    queue <int> q;
    q.push(u);
    check[u] = true;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for (int i = 0; i < listG[v].size(); i++) {
            int tmp = listG[v][i];
            if (!check[tmp]) {
                check[tmp] = true;
                q.push(tmp);
                pair <int, int> temp;
                temp.first = v;
                temp.second = tmp;
                res.push_back(temp);
            }
        }
    }
    if (res.size() > 1) {
        for (int i = 0 ; i < res.size(); i++) {
            cout << res[i].first << " " << res[i].second << endl;
        }
    } else {
        cout << "-1";
    }
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> v >> e >> s;
        for (int i = 1; i <= v; i++) {
            listG[i].clear();
        }
        for (int i = 1; i <= e; i++) {
            int d, c;
            cin >> d >> c;
            listG[d].push_back(c);
            listG[c].push_back(d);
        }
        Tree_BFS(s);
    }
    return 0;
}