#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int d = 1;
vector<int> A(105);
void print() {
    cout << "Buoc " << d++ << ": ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main() {
    cin >> n;
    for (int i = 0; i< n; i++) {
        cin >> A[i];
    }
    bool swap_check = true;
    for (int i = 0; (i < n) && (swap_check) ;i++) {
        swap_check = false;
        for (int j = 0; j < n-i-1; j++) {
            if (A[j] > A[j+1]) {
                swap(A[j],A[j+1]);
                swap_check = true;
            }
        }
        if (swap_check) print();
    }
    return 0;
}