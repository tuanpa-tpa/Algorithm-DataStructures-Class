#include <iostream>
using namespace std;
/*
2
9 2
20 3 
18
299
=>cho vị trí đầu là 1 -> trừ dần s cho 9 còn lại cộng vào số đầu
-> nếu 9*d < s -> không có số nào thỏa mãn
*/



int main() {
    int t;
    cin >> t;
    while(t--) {
        int s,d;
        cin >> s >> d;
        int A[1005] = {0};
        if (9*d < s) cout << "-1";
        else {
            int n = d;
            A[0] = 1; // gán vị trí đầu là 1
            s--;d--;
            while(s >= 9) {
                A[d] = 9; // các vị trí từ cuối lên sẽ là 9
                s -= 9;
                d--;
            }
            A[d] += s; // còn dư bao nhiêu thì cộng vào
            for (int i = 0; i< n; i++) {
                cout << A[i];
            }
        }
        cout << endl;
    }   
}