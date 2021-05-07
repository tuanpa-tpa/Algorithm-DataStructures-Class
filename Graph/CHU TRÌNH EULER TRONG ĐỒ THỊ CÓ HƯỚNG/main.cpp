#include<bits/stdc++.h>

using namespace std;
vector < int > listG[1005];
int v,e;
bool check() {
    int q = 0;
    for (int i = 1; i <= v; i++) {
        int count = 0;
        for (int j = 1; j <= v; j++) {
            for (int k = 0; k < listG[j].size(); k++) {
                if (listG[j][k] == i) {
                    count++;
                }
            }
        }
        if (count != listG[i].size()) {
            return false;
        }
    }
    return true;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 1005; i++) {
            listG[i].clear();
        }
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            int d, c;
            cin >> d >> c;
            listG[d].push_back(c);

        }
        if (check()) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    return 0;
}