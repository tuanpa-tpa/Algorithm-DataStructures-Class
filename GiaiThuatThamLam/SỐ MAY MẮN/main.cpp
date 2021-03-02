#include <iostream>

using namespace std;
/*
2
11 -> 47
10 -> -1

=> số chỉ gồm số 4 và số 7  -> s = 4x+7y
TH1: x = (s-7y)/4 -> số lượng chữ số 4 nhỏ nhất
TH2: y = (s-4x)/7 -> số lượng chữ số 7 nhỏ nhất
=> min(TH1,TH2); 
*/

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s;
        cin >> s;
        int req1 = 1000000, req2 = 1000000;
        for (int i = s; i >= 0; i--) {
            if (((s - i * 4) % 7 == 0) && (s  >= i * 4)) {
                int x = i;
                int y = (s - i * 4) / 7;
                if (req1 + req2 > x + y) {
                    req1 = x;
                    req2 = y;
                } else
                if (req1 + req2 == x + y) {
                    if (req1 > x) {
                        req1 = x;
                        req2 = y;
                    }
                }
            }
        }
        // cout << req1 << " " << req2 << endl;
        if (req1 * 4 + req2 * 7 == s) {
            for (int i = 0; i < req1; i++) {
                cout << "4";
            }
            for (int i = 0; i < req2; i++) {
                cout << "7";
            }
        } else {
            cout << "-1";
        }
    cout << endl;
    }
return 0;
}