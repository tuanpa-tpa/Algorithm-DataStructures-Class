// #include <iostream>
// #include <cmath>
// #include <algorithm>
// using namespace std;
// /*
// 2
// 4
// 4 3 2 1
// 5
// 1 2 3 4 5    1 2 3 4 5 -> key
// 1 5 4 3 2 -> 1 2 4 3 5 -> 1 2 3 4 5 
// 1 2 3 4 5 -> sau sort -> trả lại ban đầu
// => sắp xếp tăng dần -> xét xem có thay đổi vị trí không -> nếu thay đổi -> đảo lại vị trí ban đầu và d++
// 2
// 2
// */
// struct Number {
//     long long value;
//     long long key;
// };
// bool cmp1(struct Number A, struct Number B) {
//     if (A.value < B.value) return true;
//     if (A.value == B.value && A.key < B.key) return true;
//     return false;
// }

// int main() {
//     int t;
//     cin >> t;
//     while(t--) {
//         int n;
//         cin >> n;
//         struct Number A[n+2];
//         for (int i = 0; i< n; i++) {
//             cin >> A[i].value;
//             A[i].key = i;
//         }
//         stable_sort(A,A+n,cmp1);
//         int res1 = 0;
//         for (int i = 0; i< n; i++) {
//             while (A[i].key != i) { 
//                 res1++;
//                 swap(A[i],A[A[i].key]);
//             }
//         }
//         cout << res1 << endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;
int minSwap(vector < int > arr,int N) {
    int ans = 0;
    vector < int > temp(N);
    for (int i = 0; i < N; i++) {
        temp[i] = arr[i];
    }
    map < int, int > h;
    stable_sort(temp.begin(), temp.end());
    for (int i = 0; i < N; i++) {
        h[arr[i]] = i; // lưu vị trí ban đầu
    }
    for (int i = 0; i < N; i++) {
        while (arr[i] != temp[i]) {
            ans++;
            int init = arr[i];
            swap(arr[i], arr[ h[temp[i]] ]); // đổi vị trí ban đầu với vị trí đã sắp xếp
            // cập nhật map
            h[init] = h[temp[i]];
            h[temp[i]] = i;
        }
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector < int > a(n);
        for (int i = 0; i< n; i++) {
            cin >> a[i];
        }
        cout << minSwap(a, n) << endl;;
    }
    return 0;
}
