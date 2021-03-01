#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
3
4
1234567
3
3435335
2
1034

7654321
5543333
4301
*/
void backTrack(string s, int k, string& max) {
    if (k == 0) return;
    for (int i = 0; i < s.size()-1; i++) {
        for (int j = i+1; j < s.size(); j++) {
            if (s[i] < s[j]) {
                swap(s[i],s[j]); // đổi chỗ để xét max
                if (max < s) {
                    max = s;
                }
                backTrack(s,k-1,max); // tìm max tiếp theo
                swap(s[i],s[j]); // trả lại chuỗi lúc trước để tìm max tiếp
            }
        }
    }
} 
int main() {
    int t;
    cin >> t;
    while(t--) {
        int k;
        string s;
        cin >> k >> s;
        string max = s;
        backTrack(s,k,max);
        cout << max << endl;
    }
    return 0;
}


