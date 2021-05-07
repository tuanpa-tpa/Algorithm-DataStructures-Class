#include <bits/stdc++.h>
using namespace std;

int n,m,k;
string A[105];
string B[10][10];
bool check = false;
bool checkWord(string s) {
    for (int i = 0; i < k; i++) {
        if (s == A[i]) return true;
    }
    return false;
}

void backTrack(bool C[10][10], int i, int j, string& s) {
    C[i][j] = true;
    s += B[i][j];
    if (checkWord(s)) {
        cout << s << " ";
        check = true;
    }
    for (int row = i-1; row <= i+1 && row < m; row++) { // di chuyển 8 hướng
        for (int col = j-1; col <= j+1 && col < n; col++) {
            if (row >= 0 && col >= 0 && !C[row][col]) {
                backTrack(C, row, col, s);
            }
        }
    }
    C[i][j] = false;
    s.erase(s.length() - 1); // xóa đi ký tự cuối
}


void words() {
    bool C[10][10] = {false};
    string str = "";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            backTrack(C, i, j, str);
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> k >> n >> m;
        for (int i = 0; i < k; i++) {
            cin >> A[i];
        } 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> B[i][j];
            }
        }
        check = false;
        words();
        if (!check) {
            cout << "-1";
        }
        cout << endl;
    }
    return 0;
}