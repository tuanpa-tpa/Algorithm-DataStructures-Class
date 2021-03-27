#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set <long long> s; // dùng set vì trong set phần tử là duy nhất và dc sort
        set <long long>::iterator it;
        if(n == 1 || n == 2 || n == 3 || n == 4 || n == 5) cout << n;
        else {
            n--;
            s.insert(1);
            while(n) {
                // long long temp = q.top();
                // q.pop();
                // q.push(temp*2);
                // q.push(temp*3);
                // q.push(temp*5);
                it = s.begin();
                long long temp = *it;
                s.erase(it);
                s.insert(2*temp);
                s.insert(3*temp);
                s.insert(5*temp);
                n--;
            }
            cout << *s.begin();
        }
        cout << endl;
    }
    return 0;
}