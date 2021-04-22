#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        if (s[0] == '0') {
            cout << 0 << endl;
            continue;
        }
        int res[50] = {0}; // số cách mã hóa
        res[0] = 1; res[1] = 1; 
        for (int i = 2; i <= s.size(); i++) {
            if (s[i-1] > '0') {
                res[i] = res[i-1]; // nếu s[i] khác 0 thì cộng số cách trước đó
            }
            if (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')) { // số 1 có thể ghép với bất kì số nào, còn số 2 thì phải thỏa mãn đk <= 26
                res[i] += res[i-2]; // cộng thêm số cách ghép vào được
            }
        }
        cout << res[s.size()] << endl;
    }
    return 0;
}