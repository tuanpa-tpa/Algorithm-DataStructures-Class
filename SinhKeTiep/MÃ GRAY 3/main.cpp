#include <iostream>
using namespace std;
/*
01001 ->01101
01101 ->01011
=> in ra bit đầu, các bít sau nếu khác nhau in ra 1, giống nhau in ra 0 -> so sánh theo binary với nhau
g[i] = b[i-1] vs b[i]
*/
int main() {
    int t;
    cin >> t;
    while(t--) {
        string b;
        cin >> b;
        cout << b[0];
        for (int i = 1; i< b.size(); i++) {
            if (b[i] != b[i-1]) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << endl;
    }
    return 0;
}