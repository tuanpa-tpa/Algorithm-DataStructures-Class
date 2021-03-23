#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int l,r;
        cin >> l >> r;
        int res = 0;
        for (int i = l; i <= r; i++) {
            int d[10] = {0};
            int temp = i;
            bool check = false;
            while(temp) {
                int digit = temp%10;
                if (digit > 5) {
                    check = true;
                    break;
                }
                d[digit]++;
                temp /= 10;
            }
            if (check) continue;
            for (int j = 0; j <= 9; j++) {
                if (d[j] >= 2) {
                    check = true;
                    break;
                }
            }
            if (!check) res++;
        }
        cout << res << endl;
    }
    return 0;
}