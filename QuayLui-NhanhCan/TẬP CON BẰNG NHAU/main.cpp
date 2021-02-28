#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n+3];
        int sum = 0;
        for (int i = 1; i<= n; i++) {
            cin >> A[i];
            sum += A[i];
        }
        if (sum % 2 == 0) {
            bool check[100000] = {false};
            check[0] = true;
            for (int i = 1; i<= n; i++) {
                for (int j = sum/2 ; j >= A[i]; j--) {
                    if (check[j - A[i]]) check[j] = true;
                }
            }
             string s = (check[sum/2] == true) ? "YES": "NO";
             cout << s;

        } else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}