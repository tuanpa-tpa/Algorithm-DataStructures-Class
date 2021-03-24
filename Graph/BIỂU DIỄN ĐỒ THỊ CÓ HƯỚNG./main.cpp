#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int v,e;
        cin >> v >> e;
        vector < vector<int> > list(v+5) ;
        for (int i = 1; i <= e; i++) {
            int d,c;
            cin >> d >> c;
            list[d].push_back(c);
        }
        // for (int i = 1; i <= v; i++) {
        //     sort(list[i].begin(),list[i].end());
        // }
        for (int i = 1; i <= v; i++) {
            cout << i << ": ";
            for (int j = 0; j < list[i].size(); j++) {
                cout << list[i][j] << " ";
            }
            cout << endl;
        }
    }   
    return 0;
}