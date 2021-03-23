#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        queue <string> q;
        vector <string> res; 
        q.push("1"); // 1
        while(n--) {
            q.push(q.front()+"0"); // 10
            q.push(q.front()+"1"); // 11
            // res.push_back(q.front());
            cout << q.front() << " ";
            q.pop();
        }
        // for (int i = 0; i< res.size(); i++) {
        //     cout << res[i] << " ";
        // }
        cout << endl;
    }
    return 0;
}