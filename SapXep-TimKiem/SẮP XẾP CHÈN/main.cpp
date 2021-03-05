#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int d = 0;
vector<int> A(1005);
vector<int> B;
void print() {
    cout << "Buoc " << d++ << ": ";
    for (int i = 0; i < B.size(); i++) {
        cout << B[i] << " ";
    }
    cout << endl;
}
int main() {
    cin >> n;
    for (int i = 0; i< n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i< n; i++) {
        B.push_back(A[i]);
        for (int j = 1; j < B.size(); j++) {
            int temp = B[j];
            int k = j - 1;
            while(k >= 0 && temp < B[k]) {
                B[k+1] = B[k];
                k--;
            }
            B[k+1] = temp;
        }
        print();
    }
    
    return 0;
}