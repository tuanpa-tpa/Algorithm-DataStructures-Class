#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    cin >> n;
    int A[1005];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    } 
    int store[1005] = {0};
    int res = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (A[i] > A[j] && (store[j] + 1) > store[i]) {
                store[i] = store[j]+1;
                res = max(res,store[i]);
            }
        }
    }
    cout << ++res;
    return 0;
}