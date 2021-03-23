#include <iostream>
using namespace std;
int n,k;
int A[50],B[50];
bool check = true;
void sinh() {
    int i = n;
    while(A[i] == 1) {
        A[i--] = 0;
    }
    if (i > 0) {
        A[i] = 1;
    } else {
        check = false;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
        A[i] = 0;
    }
    int count = 0;
    while(check) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (A[i]) sum += B[i];
        }
        if (sum == k) {
            count++;
            for (int i = 1; i <= n; i++) {
                if (A[i]) cout << B[i] << " ";
            }
            cout << endl;
        }
        sinh(); 
    }
    cout << count;
    return 0;
}