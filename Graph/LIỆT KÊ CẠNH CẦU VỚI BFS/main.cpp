// #include <iostream>
// #include <vector>
// #include <queue>
// #include <algorithm>
// using namespace std;

// int BFS(int u, int A[1005][1005], bool B[], int n) {
//     int count = 0;
//     queue <int> q;
//     q.push(u);
//     B[u] = true;
//     while(!q.empty()) {
//         int v = q.front(); q.pop();
//         count++;
//         for (int i = 1; i <= n; i++) {
//             if (!B[i] && A[v][i]) {
//                 q.push(i);
//                 B[i] = true;
//             }
//         }
//     }
//     return count;
// }

// int main() {
//     int t;
//     cin >> t;
//     while(t--) {
//         int v,e;
//         cin >> v >> e;
//         int A[1005][1005] = {0};
//         bool B[1005] = {false};
//         for (int i = 1; i <= v; i++) {
//             for (int j = 1; j <= v; j++) {
//                 A[i][j] = 0;
//             }
//         }
//         for (int i = 1; i <= e; i++) {
//             int d,c;
//             cin >> d >> c; // chuyển vể ma trận kề
//             A[d][c] = 1;
//             A[c][d] = 1;
//         }
//         vector < vector<int> > res;
//         for (int i = 1; i <= v; i++) {
//             for (int j = 1; j <= v; j++) {
//                 if (A[i][j] == 1) {
//                     A[i][j] = 0;
//                     A[j][i] = 0;
//                     int temp = BFS(1,A,B,v);
//                     // cout << temp << " ";
//                     if (temp != v) {
//                         // vector <int> req;
//                         // req.push_back(i);
//                         // req.push_back(j);
//                         // res.push_back(req);
//                         cout << i << " " << j << " ";
//                     }
//                     // trả lại giá trị cho B
//                     for (int k = 1; k <= v; k++) {
//                         B[k] = false;
//                     }
//                     A[i][j] = 1;
//                     // A[j][i] = 1;
//                 }
//             }
//         }
//         // sort(res.begin(), res.end());
//         // for (int i = 0; i < res.size(); i++) {
//         //     for (int j = 0; j < res[i].size(); j++) {
//         //         cout << res[i][j] << " ";
//         //     }
//         // }
//         cout << endl;
//     }
//     return 0;
// }



#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int A[1005][1005];
int B[1005] = {false};
int e,v;

void input() {
    cin >> v >> e;
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            A[i][j] = 0;
        }
    }
    for (int i = 1; i <= e; i++) {
        int d, c;
        cin >> d >> c;
        A[d][c] = 1;
        A[c][d] = 1;
    }
    for (int j = 1; j <= v; j++) {
        B[j] = false;
    }
}

int BFS(int u) {
    int res = 0;
    queue <int> q;
    q.push(u);
    B[u] = true;
    while(!q.empty()) {
        int tmp = q.front();q.pop();
        res++;
        for (int i= 1; i <= v; i++) {
            if (B[i] == false && A[tmp][i] == 1) {
                B[i] = true;
                q.push(i);
            }
        }
    }
    return res;
}

void reB() {
    for (int i = 1; i <= v; i++) {
        B[i] = false;
    }
}

void canhCau() {
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (A[i][j] == 1) {
                A[i][j] = 0;
                A[j][i] = 0;
                if (BFS(1) != v) {
                    cout << i << " " << j << endl;
                }
                reB();
                A[i][j] = 1;
            }
        }
    }
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        input();
        canhCau();
        // cout << endl;
    }
    return 0;
}