#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i< n; i++) {
            cin >> A[i];
        }
        // sort(A,A+n);
        int number_Min = A[0]+A[1];
        for (int i = 0; i < n; i++){
            for (int j = i+1; j<n; j++){
                if (abs(number_Min) > abs(A[i]+A[j])) {
                    number_Min = A[i]+A[j];
                }
            }
        }
        cout << number_Min <<endl;
    }
    return 0;
}