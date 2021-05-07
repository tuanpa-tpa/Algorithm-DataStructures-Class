/**
 * a^x b^y c^z số ước = (x+1)(y+1)(z+1)
 * */

#include <bits/stdc++.h>
using namespace std;
int n;
long long res;
int v[] = {2,3,5,7,11,13,17,19,21,23,29,31};

void backTrack(int i, long long req, long long uoc) {
    if (uoc > n) return;
    if (uoc == n) {
        res = min(res,req);
    }
    for (int j = 1; ; j++) {
        if (req*v[i] > res) break;
        req *= v[i];
        backTrack(i+1,req,uoc*(j+1));
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        cin >> n;
        res = 1e18;
        backTrack(0,1,1);
        cout << res << endl;
    }
    return 0;
}