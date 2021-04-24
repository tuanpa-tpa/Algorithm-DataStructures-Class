#include <bits/stdc++.h>
using namespace std;

struct node {
    int digit;
    int count;
};

int convert(int a, int b) {
    queue <node> q;
    set <int> s;
    node t;
    t.digit = a;
    t.count = 0;
    q.push(t);
    s.insert(a);
    while(!q.empty()) {
        node temp = q.front(); q.pop();
        if (temp.digit == b) {
            return temp.count; // cận 1
        }
        if (temp.digit*2 == b || temp.digit-1 == b) {
            return temp.count+1; // cận 2
        }
        if (s.find(temp.digit*2) == s.end() && temp.digit < b) { // không tìm thấy
            t.digit = temp.digit*2;
            t.count = temp.count+1;
            q.push(t);
            s.insert(t.digit);
        }
        if (s.find(temp.digit - 1) == s.end()) { // không tìm thấy
            t.digit = temp.digit-1;
            t.count = temp.count+1;
            q.push(t);
            s.insert(t.digit);
        }
    }
    return 0;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a,b;
        cin >> a >> b;    
        cout << convert(a,b) << endl;
    }
    return 0;
}