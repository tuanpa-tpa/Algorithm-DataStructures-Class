#include <bits/stdc++.h>
using namespace std;
int binarySearch(vector <int> A, int x) {
    int left = 0, right = A.size()-1;
    bool check = false;
    while(left <= right) {
        int mid = (left+right)/2;
        int midValue = A[mid];
        if (x == midValue) {
            return 1;
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
        cout << binarySearch(A,x);
        cout << endl;
    }
    return 0;
}