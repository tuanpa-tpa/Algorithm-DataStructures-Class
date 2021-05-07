#include <bits/stdc++.h>

using namespace std;
int n,m;
int A[505][505];
bool check[505][505] = {false};
int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {-1, 1, -1, 0, 1, -1, 0, 1};
void BFS(int u, int v) {
    queue< pair<int, int> > q;
    check[u][v] = true;
    q.push({u,v});
    while(!q.empty()) {
        pair<int, int> tmp = q.front(); q.pop();
        for (int i = 0; i < 8; i++) { // xét 8 hướng
            int x = tmp.first + dx[i];
            int y = tmp.second + dy[i];
            if (A[x][y] && !check[x][y]) {
                q.push({x,y});
                check[x][y] = true;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        memset(check, false, sizeof(check));
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> A[i][j];
            }
        }
        int res =0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!check[i][j] && A[i][j]) {
                    BFS(i,j);
                    res ++;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}