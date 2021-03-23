#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,x;
int A[105];
vector <int> req;
vector < vector <int> > res;

void backTrack(int s, int tmp) {
    if (s == x) {
        res.push_back(req);
    }
    for (int j = 1; j<= n; j++) {
        if (s + A[j] > x) return ; // cận
        if ((s + A[j] <= x) && A[j] >= tmp) { // dùng tmp để loại bỏ trường hợp số sau nhỏ hơn số trước
            req.push_back(A[j]);
            backTrack(s+A[j],A[j]);
            req.pop_back();
        }
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> x;
        res.clear();
        req.clear();
        for (int i = 1; i<= n; i++) {
            cin >> A[i];
        }
        backTrack(0,0);
        // sort(res.begin(), res.end());
        if (res.empty()) cout << "-1";
        else {
            for (int i = 0; i < res.size(); i++) {
                for (int j = 0; j< res[i].size(); j++) {
                    if (j == 0) cout << "[";
                    cout << res[i][j];
                    if (j < res[i].size()-1) cout << " ";
                    else cout << "]";
                }
            }
        }
        cout << endl;
    }
    return 0;
}