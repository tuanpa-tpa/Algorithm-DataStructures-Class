#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int d = 1;
vector<int> A(1005);
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
    int minIndex;
    for (int i = 0; i < n-1; i++){
    minIndex= i;
    for (int j = i+1; j < n; j++)
        if (A[j] < A[minIndex])
        minIndex = j;
        swap(A[minIndex], A[i]);
        print();
    }
    return 0;
}