#include <bits/stdc++.h>
using namespace std;


struct node {
    int digit;
    int count;
};

int BFSConvert(int a) {
    queue <node> q;
    node t;
    t.digit = a;
    t.count = 0;
    q.push(t);
    set <long> s;
    s.insert(a);
    while(!q.empty()) {
        node temp = q.front(); q.pop();
        int digit = temp.digit;
        int count = temp.count;
        if (digit == 1) return count;
        if (digit - 1 == 1) return count+1;
        if (s.find(digit - 1) == s.end()) {
            t.digit = digit - 1;
            t.count = count + 1;
            q.push(t);
            s.insert(digit - 1);
        }
        for (int i = 2; i <= sqrt(digit); i++) { // chạy đến căn để tìm max
            if (digit % i == 0) {
                if (s.find(digit/i) == s.end()) {
                    t.digit = digit/i;
                    t.count = count + 1;
                    q.push(t);
                    s.insert(digit/i);
                }
            }
        }
    }
    return 0;
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        int a;
        cin >> a;
        cout << BFSConvert(a) << endl; 
    }
    return 0;
}