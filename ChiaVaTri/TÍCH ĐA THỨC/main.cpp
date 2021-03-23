#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
      int n,m;
      cin >> n >> m;
      int A[n+5],B[m+5];
      for (int i = 0; i < n; i++) {
          cin >> A[i];
      } 
      for (int i = 0; i < m; i++) {
          cin >> B[i];
      } 
      int temp = n + m + 5;
      int C[temp];
      for (int i = 0; i < temp; i++) {
          C[i] = 0;
      }
      for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++) {
              C[i+j] += A[i]*B[j];
          }
      }
      for (int i = 0; i < n+m-1; i++) {
          cout << C[i] << " ";
      }
      cout << endl;
    }
    return 0;
}