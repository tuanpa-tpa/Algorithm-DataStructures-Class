#include <iostream>
using namespace std;

/*
2

70 = 70/50 + 20/20 = 2

121 = 121/100 + 21/20 + 1/1 = 3

-> chia dần
*/

int main() {
    int A[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int i = 9;
        int cnt = 0;
        for (int i = 9; i>= 0; i--) {
            while (n / A[i]) {// nếu chia mà > 0
                cnt += n / A[i]; 
                n = n % A[i];
            }
        }
        cout << cnt << endl;
    }
    return 0;
}