#include <bits/stdc++.h>
using namespace std;
bool B[1000005] = {false};
void sangNT() {
    B[0] = true;
    B[1] = true;
    for (int i = 2; i <= 1000000; i++) {
        if (B[i] == false){
            for (int j = i*2 ; j<= 1000000;j+=i) {
                B[j] = true;
            }
        }
    }
}

int main() {
    sangNT();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        bool check = true;
        for (int i = 2; i<= n; i++) {
            if (!B[i] && !B[n-i]){
                cout << i << " " << n - i;
                check = false;
                break;
            }
        }
        if (check) cout << "-1";
        cout << endl;
    }
    return 0;
}