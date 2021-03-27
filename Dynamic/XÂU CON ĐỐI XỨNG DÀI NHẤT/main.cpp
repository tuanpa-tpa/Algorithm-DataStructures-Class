#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int i = 0;
        int j,k;
        int res = 0;
        while(i < s.size()) {
            j = i; k = i;
            while(k < s.size()-1 && s[k+1] == s[k]) k++;
            i = k+1;
            while(j > 0 && s[j-1] == s[k+1]) {
                j--;
                k++;
            }
            res = max(res, k-j+1);
        }
        cout << res << endl;
    }
    return 0;
}