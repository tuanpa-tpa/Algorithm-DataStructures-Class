#include <iostream>
#include <algorithm>
using namespace std;

struct congViec {
    int s;
    int f;
};

bool cmp (congViec a, congViec b) {
    if (a.f < b.f) return true;
    // else if (a.f == b.f) {
    //     if (a.s < b.s) return true;
    // }
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
            cin >> A[i].s;
        }
        for (int i = 0; i< n; i++) {
            cin >> A[i].f;
        }
        sort(A,A+n,cmp);
        // for (int i = 0 ;i < n; i++) {
        //     cout << A[i].s << " ";
        // }
        // cout << endl;
        // for (int i = 0 ;i < n; i++) {
        //     cout << A[i].f << " ";
        // }
        int d = 1;
        int i = 0;
        for (int j = 1; j< n; j++){
            if (A[j].s >= A[i].f){
                d++;
                i=j;
            }
        }
        cout << d << endl;

    }
    return 0;
}