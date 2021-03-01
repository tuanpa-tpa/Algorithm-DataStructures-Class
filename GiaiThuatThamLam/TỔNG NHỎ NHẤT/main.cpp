#include <iostream>
#include <algorithm>

using namespace std;

/*
2
6
6 8 4 5 2 3 -> 234568 - > 246+358 = 604
5
5 3 0 7 4 -> 03457 -> 47 + 35 = 82
604
82
=> sort tăng dần -> số đầu là các chữ lẻ -> số sau là các chữ số chẵn
*/

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i< n; i++) {
            cin >> A[i];
        }
        sort(A,A+n);
        // for (int i = 0; i < n; i++) {
        //     cout << A[i] << " ";
        // }
        // cout << endl;
        int i = 0;
        long num1 = 0, num2 = 0;
        while(i < n) {
            num1 = num1*10 + A[i++];
            if (i == n) break;
            num2 = num2*10 + A[i++];
        }
        cout << num1 + num2 << endl;
    }
}