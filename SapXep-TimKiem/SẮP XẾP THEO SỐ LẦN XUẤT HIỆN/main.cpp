#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a, pair<int,int> b){
    if (a.second > b.second) return true;
    if (a.second == b.second && a.first < b.first) return true;
    return false;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector< pair<int,int> > A;
        map <int,int> m;
        map <int,int>:: iterator it;
        for (int i = 0; i<n; i++) {
            int temp;
            cin >> temp;
            m[temp]++;
        }
        for (it = m.begin(); it != m.end(); it++){
            pair<int,int> ans;
            ans.first = it->first;
            ans.second = it->second;
            A.push_back(ans);
        }
        sort(A.begin(),A.end(),cmp);
        for (int i = 0; i< A.size(); i++) {
            for (int j = 0; j < A[i].second; j++) {
                cout << A[i].first << " ";
            }
        }
        cout << endl;
    }
    return 0;
}