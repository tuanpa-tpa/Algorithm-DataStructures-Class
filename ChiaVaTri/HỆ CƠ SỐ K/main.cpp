#include <iostream>
#include <string>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int k;
        string s1,s2;
        cin >> k >> s1 >> s2;
        while(s1.size() < s2.size()) s1 = "0" +s1;
        while(s1.size() > s2.size()) s2 = "0" +s2;
        int nho = 0;
        string res = "";
        for (int i = s1.size()-1 ; i >= 0; i--) {
            int temp = int(s1[i] - '0') + int(s2[i] - '0') + nho;
            res = char(temp%k + '0') + res;
            nho = temp/k;
        }
        if (nho > 0) res = char(nho + '0') + res;
        cout << res << endl;
    }
    return 0;
}