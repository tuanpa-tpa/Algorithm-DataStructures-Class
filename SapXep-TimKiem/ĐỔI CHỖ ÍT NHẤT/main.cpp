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
//     int value;
//     int key;
// };
// bool cmp(struct Number A, struct Number B) {
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
//         struct Number A[n];
//         for (int i = 0; i< n; i++) {
//             cin >> A[i].value;
//             A[i].key = i;
//         }
//         sort(A,A+n,cmp);
//         int d = 0;
//         for (int i = 0; i< n; i++) {
//             while (A[i].key != i) { // khác vị trí -> dùng while do chưa chắc swap xong nó đã về ban đầu
//                 d++;
//                 swap(A[i],A[A[i].key]);
//             }
//         }
//         cout << d << endl;
//     }
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

void swap(vector < int > & arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int minSwaps(vector < int > arr,int N) {
    int ans = 0;
    vector < int > temp = arr;
    map < int, int > h;
    sort(temp.begin(), temp.end());
    for (int i = 0; i < N; i++) {
        h[arr[i]] = i; // lưu vị trí
    }
    for (int i = 0; i < N; i++) {
        if (arr[i] != temp[i]) {
            ans++;
            int init = arr[i];
            swap(arr, i, h[temp[i]]); // đổi vị trí ban đầu với vị trí đã sắp xếp
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
        cout << minSwaps(a, n) << endl;;
    }
    return 0;
}
