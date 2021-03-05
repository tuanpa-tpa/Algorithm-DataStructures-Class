#include <iostream>
using namespace std;
int d = 1;
int A[105];
int n;
void xuat() {
    cout << "Buoc " << d++ << ": ";
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
void Sapxep() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++)
            if (A[i] > A[j])
                swap(A[i], A[j]);
        xuat();
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    Sapxep();
    return 0;
}