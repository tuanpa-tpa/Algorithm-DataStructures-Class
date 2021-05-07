#include <bits/stdc++.h>
using namespace std;

int e, v;
vector < vector <int> > listG(1005);

void DFS(int v, bool visited[]) {
    visited[v] = true;
    vector <int>::iterator i;
    for (i = listG[v].begin(); i != listG[v].end(); ++i) {
        if (!visited[*i])
            DFS(*i, visited);
    }
}
bool Euler() {
    bool visited[v+5];
    int i;
    for (i = 0; i <= v; i++) {
        visited[i] = false;
    }
    for (i = 1; i <= v; i++) { // duyệt đỉnh chưa xét 
        if (listG[i].size() != 0) {
            break;
        }
    }
    if (i == v+1) {
        return true; // xét hết đỉnh
    }
    DFS(i, visited); // duyệt đỉnh khác 0

    for (i = 1; i <= v; i++)
        if (visited[i] == false && listG[i].size() > 0) // nếu không tạo thành chu trình
            return false;
    return true;
}
int checkEuler() {
    if (!Euler()) {
        return 0;
    }
    int odd = 0;
    for (int i = 1; i <= v; i++) {
        if (listG[i].size() & 1)
            odd++;
    }
    if (odd > 2) {
        return 0;
    }
    return (odd) ? 1 : 2;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> v >> e;
        for (int i = 0; i <= v; i++) {
            listG[i].clear();
        }
        for (int i = 1; i <= e; i++) { // chuyển danh sách cạnh sang kề
            int d, c;
            cin >> d >> c;
            listG[d].push_back(c);
            listG[c].push_back(d);
        }
        // for (int i = 1; i <= v; i++) {
        //     cout << i << ": ";
        //     for (int j = 0; j < listG[i].size(); j++) {
        //         cout << listG[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        cout << checkEuler();
        cout << endl;
    }
    return 0;
}