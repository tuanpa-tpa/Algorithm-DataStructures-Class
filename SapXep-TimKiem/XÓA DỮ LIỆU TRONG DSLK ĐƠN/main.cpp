#include <iostream>
#include <string>
using namespace std;

int main() {
       int n,x;
       cin >> n;
       int A[n];
       for (int i = 0; i < n; i++) {
           cin >> A[i];
       }
       cin >> x;
       for (int i = 0; i < n; i++) {
           if (A[i] != x) {
               cout << A[i] << " ";
           }
       }
    return 0;
}