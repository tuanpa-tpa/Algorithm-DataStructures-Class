// #include <bits/stdc++.h>

// using namespace std;

// int v, e;
// vector < vector < int > > listG(1005);
// int visited[1005];

// bool BFS(int s) {
//     queue < int > q;
//     visited[s] = 1;
//     q.push(s);
//     while (!q.empty()) {
//         int u = q.front(); q.pop();
//         for (int i = 0; i < listG[u].size(); i++) {
//             int tmp = listG[u][i];
//             if (visited[tmp] == 0) {
//                 visited[tmp] = 1;
//                 q.push(tmp);
//             } else if (visited[tmp] == 1) {
//                 return true;
//             }
//         }
//         visited[u] = 2;
//     }
//     return false;
// }

// string checkCycle() {
//     memset(visited,0, sizeof(visited));
//     for (int i = 1; i <= v; i++)
//         if (!visited[i] && BFS(i))
//             return "YES";
//     return "NO";
// }

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         cin >> v >> e;
//         for (int i = 1; i <= v; i++) {
//             listG[i].clear();
//         }
//         for (int i = 1; i <= e; i++) {
//             int d, c;
//             cin >> d >> c;
//             listG[d].push_back(c);
//             listG[c].push_back(d);
//         }
//         cout << checkCycle() << endl;
//     }
//     return 0;
// }




#include <bits/stdc++.h>

using namespace std;
int v, e;
vector < vector < int > > listG(1005);

bool BFS(int s, vector < int > & visited) {
    queue < int > q;
    visited[s] = 1;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = 0; i < listG[u].size(); i++) {
            int tmp = listG[u][i];
            if (visited[tmp] == 0) {
                visited[tmp] = 1;
                q.push(tmp);
            } else if (visited[tmp] == 1) {
                return true;
            }
        }
        visited[u] = 2;
    }
    return false;
}

string checkCycle() {
    vector < int > visited(v+5, 0);
    for (int i = 1; i <= v; i++)
        if (!visited[i] && BFS(i, visited))
            return "YES";
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
            listG[c].push_back(d);
        }
        cout << checkCycle() << endl;
    }
    return 0;
}