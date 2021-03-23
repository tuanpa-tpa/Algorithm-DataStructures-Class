#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,s;
        cin >> n >> s;
        bool A[50000] = {false};
        A[0] = true;
        for (int i = 1; i <= n; i++) {
            int temp;
            cin >> temp;
            A[temp] = true;
            for (int j = s ;j >= temp; j--) {
                if (A[j-temp]) {
                    A[j] = true;
                }
            }
        }
        if (A[s]) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}