#include <iostream>
using namespace std;
int n,k;
int A[100];
bool check;

void xuat(){
    for (int i = 1; i<= k; i++){
        if (i == 1) cout << "(";
        cout << A[i];
        if (i < k) cout << " ";
        else cout << ") ";
    } 
}

void sinh(){
    int i = k;
    while(i>=1 && A[i] == 1) i--;
    if (i >= 1){
        A[i]--;
        int d = k-i+1; // tổng các phần tử sau nó
        for (int j = i+1; j <= i+d/A[i]; j++) { // xem tổng các phẩn tử phía sau nó có >= nó không
            A[j] = A[i];
        }
        k = i; // reset độ dài của dãy
        k += d/A[i]; // cộng lại số phần tử
        if (d % A[i]) { // nếu nó chia mà còn dư thì cộng cái số dư vô sau mảng
            k++;
            A[k] = d % A[i];
        }
    } else {
        check = false;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        k = 1;
        A[k] = n;
        check = true;
        while(check){
            xuat();
            sinh();
        }
        cout << endl;
    }
    return 0;
}
