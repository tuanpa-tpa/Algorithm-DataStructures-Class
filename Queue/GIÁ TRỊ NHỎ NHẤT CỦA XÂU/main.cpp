#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        long long k;
        cin >> k >> s;
        map <char,long long> m;
        map <char,long long> ::iterator it;
        priority_queue <long long, vector<long long> > pq;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++;
        }
        for (it = m.begin(); it != m.end(); it++) {
            pq.push(it->second);
        }
        while(k--) {
            int temp = pq.top();pq.pop();
            temp--;
            pq.push(temp);
        }
        long long res = 0;
        while(!pq.empty()){
            res += pq.top()*pq.top();
            pq.pop();
        }
        cout << res << endl;
    }
    return 0;
}