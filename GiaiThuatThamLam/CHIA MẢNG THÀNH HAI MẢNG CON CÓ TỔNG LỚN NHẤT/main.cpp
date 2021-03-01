#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/*
2
5 2
8 4 5 2 10 -> 2 4 5 8 10 -> {2 4} {5 8 10} hoặc có thể ngược lại
8 3
1 1 1 1 1 1 1 1

17
2
*/

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
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
        long sum1 = 0, sum2 = 0;
        int MAX = 0;
        for (int i = 0; i < n; i++) {
            if (i < k) {
                sum1 += A[i];
            } else {
                sum2 += A[i];
            }
        }
        MAX = abs(sum2 - sum1);
        sum1 = 0; sum2 = 0;
        for (int i = 0; i < n; i++) {
            if (i < n-k) {
                sum1 += A[i];
            } else {
                sum2 += A[i];
            }
        }
        if (abs(sum1-sum2) > MAX) {
            MAX = abs(sum1 - sum2);
        };
        cout <<  MAX << endl;
    }
}