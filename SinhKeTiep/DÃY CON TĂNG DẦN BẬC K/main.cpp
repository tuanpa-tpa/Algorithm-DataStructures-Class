#include <iostream>
#include <vector>
using namespace std;

int A[105];
int B[105];
int d = 0;
int n,k;
bool check(){
    for (int i = 1; i < k; i++) {
    if (B[A[i]] > B[A[i+1]]) {
            return false;
        }
    }
    return true;
}

void sinh(int i) {
    for (int j = A[i-1]+1; j <= n; j++) {
        A[i] = j;
        if (i == k) {
            if (check()) {
                d++;
            }
        } else {
            sinh(i+1);
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    A[0] = 0;
    sinh(1);
    cout << d;
    return 0;
}