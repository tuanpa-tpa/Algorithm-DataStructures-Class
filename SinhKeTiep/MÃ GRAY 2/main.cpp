#include <iostream>
using namespace std;
/*
01101 -> 01011
01001 -> 01101
=> in ra bit đầu, các bít sau nếu khác nhau in ra 1, giống nhau in ra 0 -> so sánh binary với gray
b[i] = b[i-1] vs g[i]
*/
int main() {
    int t;
    cin >> t;
    while(t--) {
        string g,b;
        cin >> g;
        b += g[0];
        for (int i = 1; i< g.size(); i++) {
            if (g[i] != b[i-1]) {
                b += "1";
            } else {
                b += "0";
            }
        }
        cout << b << endl;
    }
    return 0;
}