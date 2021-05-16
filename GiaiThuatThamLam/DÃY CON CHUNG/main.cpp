#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,m,k;
        cin >> n >> m >> k;
        vector <int> A;
        vector <int> B;
        vector <int> C;
        vector <int>::iterator it;
        int temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            A.push_back(temp);
        }
        for (int i = 0; i < m; i++) {
            cin >> temp;
            B.push_back(temp);
        }
        for (int i = 0; i < k; i++) {
            cin >> temp;
            C.push_back(temp);
        }
        vector <int> res1(1000000);
        vector <int> res2(1000000);
        it = set_intersection(A.begin(), A.end(), B.begin(), B.end(), res1.begin());
        res1.resize(it-res1.begin());
        it = set_intersection(res1.begin(), res1.end(), C.begin(), C.end(), res2.begin());
        res2.resize(it-res2.begin());
        if (res2.empty()) cout << "NO";
        for ( it = res2.begin(); it != res2.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}