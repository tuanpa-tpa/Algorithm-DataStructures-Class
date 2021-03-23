#include <iostream>
#include <queue>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        cin >> n;
        long long temp = 1;
        for (int i = 1; i<= n; i++) {
            temp *=10;
        }
        queue <long long> q;
        q.push(6);
        q.push(8);
        vector<long long> res;
        while(q.front() / temp < 1) {
            q.push(q.front()*10+6);
            q.push(q.front()*10+8);
            res.push_back(q.front());
            q.pop();
        }
        for (int i = res.size()-1; i>= 0; i--) {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}