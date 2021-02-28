#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int A[20][20];
bool check[20][20];
vector <string> s;

void backTrack(int i, int j, string st) {
    if (A[i][j] == 0 || A[n][n] == 0) {
        return;
    }
    if (i == n && j == n) {
        s.push_back(st);
        return;
    }
    if (j+1 <= n && A[i][j+1] == 1 && !check[i][j+1]) {
        check[i][j+1] = true;
        backTrack(i,j+1,st+"R");
        check[i][j+1] = false;
    }
    if (i+1 <= n && A[i+1][j] == 1 && !check[i+1][j]) {
        check[i+1][j] = true;
        backTrack(i+1,j,st+"D");
        check[i+1][j] = false;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for (int i = 1; i<= n; i++ ){
            for (int j = 1; j<= n; j++ ) {
                cin >> A[i][j];
            }
        }    
        s.clear();
        backTrack(1,1,"");
        if (s.size()) {
            sort(s.begin(),s.end());
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