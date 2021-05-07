#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int v,e,f,s;
vector < vector <int> > list(1005);
vector < int > req(1005);
int B[1005];

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> v >> e >> f >> s;
        for (int i = 1; i <= e; i++) {
            int d,c;
            
            cin >> d >> c;
            list[d].push_back(c);
            list[c].push_back(d);
        }
    }
    return 0;
}