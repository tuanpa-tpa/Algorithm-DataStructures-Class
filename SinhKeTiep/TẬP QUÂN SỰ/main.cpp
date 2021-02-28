#include <iostream>
using namespace std;
/*
5 3
1 3 5 -> 1 4 5 => số 3 bị đẩy ra -> 1
5 3
1 4 5 -> 2 3 4 => số 1 và 5 bị đẩy ra -> 2
6 4
3 4 5 6 -> cấu hình ban đầu -> cả 4 người nghỉ

=> xét cấu hình tiếp theo khác cấu hình trước đó bao nhiêu số => số lính được nghỉ
*/

int n,k;
int A[45];
int B[45]; //  tạo mảng lưu trữ số vị trí lính ban đầu
int sinh() {
    int count = 0;
    int C[45] = {0}; // tạo mảng đếm các lính được nghỉ
    int i = k;
    while(A[i] == n-k+i){
        i--;
    }
    if (i >= 1) {
        A[i]++;
        C[A[i]]++; // lính tại vị trí đấy đã được dùng
        for (int j = i+1; j<= k; j++) {
            A[j] = A[j-1] +1;
            C[A[j]]++; // lính tại vị trí đấy đã được dùng
        }
    } else {
        return k;
    }
    for (int j = i; j<= k; j++) { // các lính từ 1->i chắc chắn được dùng => chỉ xét từ i -> k
        if (C[B[j]] == 0) count++;
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        for (int i = 1; i<= k; i++) {
            cin >> A[i];
            B[i] = A[i];
        }
        cout << sinh() << endl;
    }
    return 0;
}