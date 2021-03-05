#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int A[n];
        int B[n];
        for (int i = 0; i< n; i++) {
            cin >> A[i];
            B[i] = A[i];
        }
        sort(B,B+n);
        int index1=0, index2 = n-1;
        while(A[index1] == B[index1]) index1++; // tìm vị trí đầu tiên chưa sắp xếp
        while(A[index2] == B[index2]) index2--; // tìm vị trí cuối dùng chưa sắp xếp
        if (index1 > index2) swap(index1,index2); // kiểm tra điều kiện nếu index 1> 2
        cout << ++index1 << " " << ++index2 << endl;
    }
    return 0;
}