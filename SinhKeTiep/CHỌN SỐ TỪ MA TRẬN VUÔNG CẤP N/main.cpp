#include <iostream>
#include <vector>
using namespace std;

/*
3 10
2 4 3
1 3 6
4 2 4

2
1 3 2
3 2 1
=> đáp án là các hoán vị của n -> chỉ cần hoán vị giá trị trên các hàng của ma trận 
-> mỗi hàng được 1 giá trị -> cộng lại nếu bằng k => kq
*/
int n,k;
int A[105][105];
int B[105];
bool check[105] = {false};
vector< vector<int> > res;
void backTrack(int i) {
    for (int j = 1; j<=n; j++) {
        if (!check[j]) {
            check[j] = true;
            B[i] = j;
            if (i == n) {
                int temp = 0;
                for (int k = 1; k <= n; k++) {
                    temp += A[k][B[k]];
                } 
                if (temp == k) {
                    vector <int> req; // tạo 1 vector để lưu trữ từng test
                    for (int k = 1; k<=n; k++) {
                        req.push_back(B[k]);
                    }
                    res.push_back(req);
                }
            } else {
                backTrack(i+1);
            }
            check[j] = false;
        }
    }
}


int main() {
    cin >> n >> k;
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j<= n; j++) {
            cin >> A[i][j];
        }
    }
    backTrack(1);
    cout << res.size() << endl;
    for (int i = 0; i< res.size(); i++) {
        for (int j = 0; j< res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}