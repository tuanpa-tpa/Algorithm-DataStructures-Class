#include <iostream>
using namespace std;
/*
5 3
3 4 5
2 4 5
2 3 4
1 4 5
1 3 5
1 3 4
1 2 5
1 2 4
1 2 3
-> xét từ phải qua trái, nếu phần từ trước mà nhỏ 1 đơn vị thì giảm vị trí xét
sau khi xét xong thì giảm giá trị của vị trí đấy đi 1 đơn vị và các số sau nó sẽ 
có giá trị là n-k+j
*/
int n, k;
int A[1005];
void sinh() {
    int i = k;
    while (A[i-1] == A[i]-1) i--;
    if (i >= 1) {
        A[i]--;
        for (int j = i+1; j<= k; j++) {
            A[j] = n-k+j;
        }   
    } 
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        bool kt = true;
        for (int i = 1; i<= k; i++) {
            cin >> A[i];
            if (A[i] != i) kt = false;
        }
        if (!kt) {
            sinh();
            for (int i = 1; i<= k; i++) {
                cout << A[i] << " ";
            }
        } else {
            for (int i = 1; i<= k; i++) {
                cout << n-k+i << " ";
            }
        }
        cout << endl;
    }

    return 0;
}