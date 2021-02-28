#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int A[105][105];
bool check[105][105];
int d;

void backTrack(int i, int j) {
    if (i == n && j == m) {
        d++;
        return;
    }
    if (j+1 <= m && !check[i][j+1]) {
        check[i][j+1] = true;
        backTrack(i,j+1);
        check[i][j+1] = false;
    }
    if (i+1 <= n && !check[i+1][j]) {
        check[i+1][j] = true;
        backTrack(i+1,j);
        check[i+1][j] = false;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        for (int i = 1; i<= n; i++ ){
            for (int j = 1; j<= m; j++ ) {
                cin >> A[i][j];
            }
        }    
        d = 0; 
        backTrack(1,1);
        cout << d;
        cout << endl;
    }
    return 0;
}