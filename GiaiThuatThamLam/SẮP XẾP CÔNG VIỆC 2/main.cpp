#include <iostream>
#include <algorithm>
using namespace std;

struct congViec {
    int id;
    int deadline;
    int profit;
};

bool cmp (congViec a, congViec b) {
    if (a.profit > b.profit) return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        congViec A[n];
        for (int i = 0; i< n; i++) {
            cin >> A[i].id;
            cin >> A[i].deadline;
            cin >> A[i].profit;
        }
        sort(A,A+n,cmp);
        int d = 0;
        bool check[1005] = {false};
        int res = 0;
        for (int i = 0; i < n; i++) {
            while(A[i].deadline > 0 && check[A[i].deadline]) 
                A[i].deadline--;
            if (A[i].deadline > 0 && !check[A[i].deadline]) {
                d++;
                res += A[i].profit;
                check[A[i].deadline] = true;
            }
        }
        cout << d << " " << res << endl;
    }
    return 0;
}