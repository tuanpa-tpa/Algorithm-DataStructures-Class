#include <iostream>
#include <string>
using namespace std;

int main() {
       int n;
       cin >> n;
       int A[100000] = {0};
       int B[100000];
       for (int i = 0; i < n; i++) {
           cin >> B[i];
           A[B[i]]++;
       }
       for (int i = 0; i < n; i++) {
           if (A[B[i]] >= 1) {
               A[B[i]] = 0;
               cout << B[i] << " ";
           }
       }
    return 0;
}