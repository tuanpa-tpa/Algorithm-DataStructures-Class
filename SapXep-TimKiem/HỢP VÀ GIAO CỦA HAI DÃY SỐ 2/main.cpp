#include <iostream>     
#include <algorithm>    
#include <vector>     
using namespace std;
int main () {
    int t;
    cin >> t;
    while(t--){
        int n,m;
        vector<int> first;
        vector<int> second;
        vector<int> res1(100005);       
        vector<int> res2(100005);       
        vector<int>::iterator it;
        cin >> n >> m;
        int temp;
        for (int i = 0; i< n; i++) {
            cin >> temp;
            first.push_back(temp);
        }
        for (int i = 0; i< m; i++) {
            cin >> temp;
            second.push_back(temp);
        }
        sort(first.begin(),first.end());
        sort(second.begin(),second.end());
        it = set_union(first.begin(), first.end(), second.begin(), second.end(), res2.begin());
        res2.resize(it-res2.begin());
        for (it=res2.begin(); it!=res2.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
        it = set_intersection(first.begin(), first.end(), second.begin(), second.end(), res1.begin());
        res1.resize(it-res1.begin());
        for (it=res1.begin(); it!=res1.end(); ++it){
            cout << *it << " ";
        }
        cout << endl;
    }

  return 0;
}