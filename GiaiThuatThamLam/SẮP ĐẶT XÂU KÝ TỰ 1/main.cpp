#include <iostream>
#include <string>
using namespace std;

/*
3
geeksforgeeks
bbbabaaacd -> a:4 b:4 c:1 d:1  -> length(s) = 10 - > 10 - 4 = 6
bbbbb
1
1
-1
*/

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int A[200] = {0};
        int MAX = 0;
        for (int i = 0; i < s.size(); i++) {
            A[s[i]]++;
            if (A[s[i]] > MAX) {
                MAX = A[s[i]];
            }
        }
        // bool check = true;
        if (s.size() % 2 == 0) {
            if (MAX <= s.size() - MAX) cout << "1"; // phải đủ chỗ đễ xếp max
            else cout << "-1";
        } else {
            if (MAX <= s.size()/2+1) cout << "1"; // ababa -> a * a * a
            else cout << "-1";
        }
        cout << endl;
    }
    return 0;
}