#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,s,m;
        cin >> n >> s >> m;
        int temp = s/7; // số ngày chủ nhật không thể mua lương thực
        if (s*m > n*(s - temp)) { // nếu số lượng mình ăn lớn hơn số lượng mình mua thì chết đói oke
            cout << "-1";
        } else {
            for (int i = 1; i <= s-temp; i++) { // xét từ ngày đầu đến ngày có thể mua lương thực
                if (i*n >= s*m) { // mua lương thực -> nếu số lượng lương thực vừa đủ cho ngày phải sống
                    cout << i; 
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}