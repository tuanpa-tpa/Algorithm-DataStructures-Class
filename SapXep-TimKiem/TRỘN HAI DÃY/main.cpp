#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n,m;
        cin >> n >> m;
        vector<int> A;
        int temp;
        for (int i = 0; i< n+m; i++) {
            cin >> temp;
            A.push_back(temp);
        }
        sort(A.begin(),A.end());
        for (int i = 0; i< n+m; i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    return 0;
}