#include <iostream>
#include <algorithm>
using namespace std;
int A[20];
int B[20][20];
bool col[20]= {false}, cheo1[20] = {false}, cheo2[20] = {false}; 
int MAX;
void check() {
    int sum = 0;
    for (int i = 1; i<= 8; i++) {
        sum += B[i][A[i]]; // cộng tổng các vị trí lại với nhau
        // cout << i << " " << A[i] << " ";
    }
    MAX = max(sum, MAX); // tìm max
    // cout << endl;
}

void backTrack(int i) {
    for (int j = 1; j<= 8; j++) {
        if (!col[j] && !cheo1[i-j+8] && !cheo2[i+j-1]) { // nếu chưa được chọn
            A[i] = j;
            col[j] = true;
            cheo1[i-j+8] = true;
            cheo2[i+j-1] = true;
            if (i == 8) {
                check();
            } else {
                backTrack(i+1);
            }
            col[j] = false;
            cheo1[i-j+8] = false;
            cheo2[i+j-1] = false;
        }
    }
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        for (int i = 1; i<= 8; i++) {
            for (int j = 1; j<= 8; j++) {
                cin >> B[i][j];
            }
        }
        MAX = 0;
        backTrack(1);
        cout << MAX << endl;
    }
    return 0;
}