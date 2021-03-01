#include <iostream>
using namespace std;

int n,k,s;
int cnt = 0;
int A[105];
void check() {
    int sum = 0;
    for (int i = 1; i<= k; i++) {
        sum += A[i];
    }
    if (sum == s) cnt++;
}

void backTrack(int i) {
    for (int j = A[i-1]+1; j <= n-k+i; j++) {
        A[i] = j;
        if (i == k) {
            check();
        } else {
            backTrack(i+1);
        }
    }
}

int main() {
    while(true) {
        cin >> n >> k >> s ;
        if (n < k) {
            cout << "0" << endl;
            continue;
        }
        if (n == 0 && k == 0 && s == 0) break;
        cnt = 0;
        for (int i = 1; i<= k; i++) {
            A[i] = i;
        }
        backTrack(1);
        cout << cnt << endl;
    }
    return 0;
}