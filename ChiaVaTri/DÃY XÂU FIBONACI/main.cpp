#include <bits/stdc++.h>
using namespace std;
/*

*/
int main() {
    long long A[100]; // lưu thông số fibonacil
    A[1] = 1; A[2] = 1;      
    for (int i = 3; i<= 93; i++){
        A[i] = A[i-1] + A[i-2];
    }
    int t;
    cin >> t;
    while(t--) {
        long long n,k;
        cin >> n >> k; 
        while(n > 2) {
            if (k <= A[n-2]){
                n -= 2; // vì nó ở xâu đầu
            } else {
                k = k - A[n-2]; // khi nó ở dãy sau thì ta trừ đi độ dài dãy đầu sẽ ra vị 
                // trí của nó ở dãy đầu
                n--; // vì nó đang ở dãy sau
            }
        }
        if (n == 1) cout << "A";
        else cout << "B";
        cout << endl;
    }
    return 0;
}