#include <iostream>
using namespace std;
/*
0
1

0 0
0 1
11
10

-> hàng 1 đối xứng với nhau bằng số phần tử
-> hàng 2 thêm 0 trước n/2 phần từ và thêm 1 vào trước số phần tử còn lại

000 
001 
011 
010 
110 
111 
101 
100 
*/
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int grayCount = 1;
        for (int i = 1; i<= n; i++) {
            grayCount *= 2;
        }
        string s[grayCount+5];
        s[1] ="0"; s[2] ="1";
        if (n >= 2) {
            int tempCount = 2;
            for (int i = 2; i<=n; i++){
                int temp = 1;
                for (int j = 1; j<= i; j++) {
                    temp *= 2;
                }
                for (int j = 1; j<= tempCount; j++) {
                    s[temp-j+1] = "1" + s[j];
                    s[j] = "0" + s[j];
                }
                tempCount = temp;
            }
        }
        for (int i = 1; i<= grayCount; i++) {
            cout << s[i] << " ";
        }
        cout << endl;
    }

    return 0;
}