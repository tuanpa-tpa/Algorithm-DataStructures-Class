#include <iostream>
#include <queue>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long  n;
        cin >> n;
        queue <long long> q;
        q.push(1);
        int res = 0;
        // 1 10 11
        while(q.front()/n <= 1) {
            q.push(q.front()*10);
            q.push(q.front()*10+1);
            q.pop();
            res++;
            if (q.front()/n == 1 &&  q.front() % n != 0) res--;
        }
        cout << res << endl;
    }
    return 0;
}