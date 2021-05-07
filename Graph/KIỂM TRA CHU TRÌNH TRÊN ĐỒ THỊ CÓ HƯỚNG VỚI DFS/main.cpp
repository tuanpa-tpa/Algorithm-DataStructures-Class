#include <bits/stdc++.h>

using namespace std;
int v, e;
vector < vector < int > > listG(1005);
bool check = false;
void DFS(int s, int tmp, vector < bool > visited) {
    visited[s] = true;
    for (int i = 0; i < listG[s].size(); i++) {
        int t = listG[s][i];
        if (!visited[t]) {
            DFS(t, s, visited);
        } else if (t != tmp) {
            check = true;
        }
    }
}

string checkCycle() {
    check = false;
    for (int i = 1; i <= v; i++) {
        vector < bool > visited(v+5, false);
        DFS(i, 0 ,visited );
        if (check) return "YES";
    }
    return "NO";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> v >> e;
        for (int i = 1; i <= v; i++) {
            listG[i].clear();
        }
        for (int i = 1; i <= e; i++) {
            int d, c;
            cin >> d >> c;
            listG[d].push_back(c);
        }
        cout << checkCycle() << endl;
    }
    return 0;
}