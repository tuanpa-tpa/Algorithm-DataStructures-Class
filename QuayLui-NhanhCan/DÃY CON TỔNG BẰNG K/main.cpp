#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
2
5 50

5  10 15 20  25
8  53
15  22  14  26  32  9  16  8

[5 10 15 20] [5 20 25] [10 15 25]
[8 9 14 22] [8 14 15 16] [15 16 22]

=> dùng sinh nhị phân -> tại vị trí có giá trị 1 thì ta cộng lại -> kiểm tra xem có bằng s không? -> in ra
=> do in ra theo thứ tự từ điển nên ta phải sort mảng ban đầu và sort res
*/



int n,s;
int A[20];
int B[20];
vector < vector <int> > res;

void backTrack(int i) {
    for (int j = 0; j <= 1; j++) {
        B[i] = j;
        if (i == n) {
            int temp = 0;
            for (int k = 1; k <= n; k++) {
                if (B[k]) temp += A[k];
            }
            if (temp == s) {
                vector <int> req;
                for (int k = 1; k <= n; k++) {
                    if (B[k])
                        req.push_back(A[k]);
                }
                res.push_back(req);
            } 
        } else {
            backTrack(i+1);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> s;
        for (int i = 1; i<= n; i++) {
            cin >> A[i];
        }
        sort(A+1,A+n+1);
        res.clear();
        backTrack(1);
        if (res.size()){
            sort(res.begin(),res.end());
            for (int i = 0; i < res.size(); i++) {
                cout << "[";
                for (int j = 0; j< res[i].size()-1; j++) {
                    cout << res[i][j] << " ";
                }
                cout << res[i][res[i].size()-1] << "] ";
            }
        } else {
            cout << "-1";
        }
        cout << endl;
    }
    return 0;
}