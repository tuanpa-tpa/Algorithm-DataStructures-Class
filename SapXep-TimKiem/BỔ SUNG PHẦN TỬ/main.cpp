#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int,int> m;
        int numberMin = 1e9, numberMax = -1e9;
        for (int i = 0; i< n; i++) {
            int temp;
            cin >> temp;
            numberMax = max(numberMax, temp);
            numberMin = min(numberMin, temp);
            m[temp]++;
        }
        int res =0;
        for (int i = numberMin; i< numberMax; i++) {
            if (!m[i]) {
                res++;
            }
        }
        cout << res <<endl;
    }
    return 0;
}