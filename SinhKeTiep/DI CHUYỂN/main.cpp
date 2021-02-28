#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
    DDRDRRDR DDRDRRRD DRDDRRDR DRDDRRRD DRRRRDDD ->  theo thứ tự từ điển
    DRRRRDDD DRDDRRRD DRDDRRDR DDRDRRRD DDRDRRDR
    DDRDRRDR DDRDRRRD DRDDRRDR DRDDRRRD DRRRRDDD -> ok đúng r
*/



int n;
vector <string> s;
int A[50][50];
bool check[50][50] = {false};

void backTrack(int i, int j, string str) {
    if (A[1][1] == 0 || A[n][n] == 0) { // không đi được
        return;
    }
    if (i == n && j == n) { // đi đến đích thì lưu giá trị
        s.push_back(str);
        return;
    }
    // phải
    if (j+1 <= n && A[i][j+1] == 1 && !check[i][j+1]) {
        check[i][j+1] = true;
        backTrack(i,j+1,str+"R");
        check[i][j+1] = false;
    }
    // xuống
    if (i+1 <= n && A[i+1][j] == 1 && !check[i+1][j]) {
        check[i+1][j] = true;
        backTrack(i+1,j,str+"D");
        check[i+1][j] = false;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 1; i<= n; i++) {
            for (int j = 1; j<= n; j++) {
                cin >> A[i][j];
            }
        }
        s.clear();
        backTrack(1,1,"");
        if (s.size()) {
            sort(s.begin(),s.end()); // dùng thư viện cho nhanh :<
            for (int i = 0; i< s.size(); i++) {
                cout << s[i] << " ";
            }
        } else {
            cout << "-1";
        }
        cout << endl;
    }
    return 0;
}