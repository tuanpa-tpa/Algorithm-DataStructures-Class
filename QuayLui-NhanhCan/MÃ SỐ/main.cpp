#include <bits/stdc++.h>
using namespace std;
vector < vector <string> > res;
bool check[100] = {false};
int A[100];
int B[100];
int n;
string s = "";
void Try2(int i) {
    for (int j = 1; j <= n; j++) {
        B[i] = j;
        if (i == n) {
            string s2 = s;
            vector <string> req;
            for (int k = 1; k<= n; k++) {
                s2 += char(B[k] + '0');
            }
            req.push_back(s2);
            res.push_back(req);
        } else {
            Try2(i+1);
        }
    }
}

void Try1(int i) {
    for (int j = 1; j <= n; j++) {
        if (!check[j]) {
            A[i] = j;
            check[j] = true;
            if (i == n) {
                s.clear();
                for (int k = 1; k <= n; k++) {
                    s += char(A[k] + 'A'-1);
                }
                Try2(1);
            } else {
                Try1(i+1);
            }
            check[j] = false;
        }
    }
}


int main() {
    cin >> n;
    Try1(1);
    sort(res.begin(),res.end());

    for (int i = 0; i < res.size(); i++) {
        for(int j = 0; j < res[i].size(); j++) {
            cout << res[i][j];
        }
        cout << endl;
    }
    return 0;
}