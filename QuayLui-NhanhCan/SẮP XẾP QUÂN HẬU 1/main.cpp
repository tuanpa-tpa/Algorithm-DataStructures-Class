#include <iostream>
using namespace std;

int n, d;
bool A[100] = {false}, cot,cheo1[100] = {false}, cheo2[100] = {false}; 

void backTrack(int i) {
    for (int j = 1; j <= n; j++) {
        if (!A[j] && !cheo1[i-j+n] && !cheo2[i+j-1]) { // cột và 2 đường chéo chưa được chọn
            // A[i] = j;
            A[j] = true;
            cheo1[i-j+n] = true;
            cheo2[i+j-1] = true;
            if (i == n) {
                d++;
            } else {
                backTrack(i+1);
            }
            A[j] = false;
            cheo1[i-j+n] = false;
            cheo2[i+j-1] = false;
        }
    }
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        d = 0;
        backTrack(1);
        cout << d << endl;
    }
    return 0;
}