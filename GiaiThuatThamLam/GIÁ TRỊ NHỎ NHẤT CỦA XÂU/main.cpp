#include <iostream>
#include <map>
#include <queue>
#include <vector>
#include <string>
using namespace std;

/*
2
2
ABCCBC -> A:1 B:2 C:3
2
AAAB
6
2
=> xóa đi kí k tự xuất hiện nhiều nhất trong chuỗi
->  sau khi xóa 1 ký tự thì phải sắp xếp lại mảng gán số lần xuất hiện ký tự đấy -> xóa tiếp
*/

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        int k;
        cin >> k >> s;
        map <char, int> m;
        map<char, int>::iterator itm;
        for (int i = 0; i < s.size(); i++) {
            m[s[i]]++; // duyệt số lần xuất hiện vô map
        }
        priority_queue <int> pq;
        for (itm = m.begin(); itm != m.end(); itm++) {
            pq.push(itm->second); // lấy số lần xuất hiện cho vô pq
        }
        while (k) { // trừ dần
            int temp = pq.top();pq.pop(); // lần phần tử max
            temp--;
            k--;
            pq.push(temp);
        }
        long long res = 0;
        while (!pq.empty()) {
            int temp = pq.top();
            res += temp*temp;
            pq.pop();
        }
        cout << res << endl;
    }
    return 0;
}