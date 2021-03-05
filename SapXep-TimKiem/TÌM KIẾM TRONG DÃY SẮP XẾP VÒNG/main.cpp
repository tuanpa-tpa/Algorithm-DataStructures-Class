#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector <int> A, int x, int low, int high) {
    int left = low, right = high;
    while(left <= right) {
        int mid = (left+right)/2;
        int midValue = A[mid];
        if (x == midValue) {
            return mid;
        } else if (x < midValue) right = mid - 1;
        else if (x > midValue) left = mid +1;
    }
    return -1;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,x;
        cin >> n >> x;
        vector<int> A(n);
        for (int i = 0; i<n; i++) {
            cin >> A[i];
        }
        int i = 1;
        while(A[i-1] <= A[i]) i++;
        int num1 = binarySearch(A,x,0,i-1);
        int num2 = binarySearch(A,x,i+1,n-1);
        if (num1 != -1) {
            cout << ++num1;
        } else {
            cout << ++num2;
        }
        cout << endl;
    }
    return 0;
}