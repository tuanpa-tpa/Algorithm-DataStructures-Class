// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// /*
//     (5) (4 1)  (3 2)  (3 1 1) (2 2 1)  (2 1 1 1)  (1 1 1 1 1)
//     (5) (4 1) (3 2) (3 1 1) (2 2 1) (2 1 1 1) (1 1 1 1 1) 
// */
// bool check;
// int n;
// vector<int> A;
// void xuat() {
//     cout << "(";
//     for (int i = 0; i< A.size()-1; i++) {
//         cout << A[i] << " "; 
//     }
//     cout << A[A.size()-1]<<") ";
// }
// void sinh() {
//     int i = A.size()-1;
//     while (A[i] == 1) {
//         i--;
//     }
//     if (i >= 0) {
//         A[i]--;
//         if (A.size() == 1){
//             A.push_back(1);
//         } else if (A[i] == 1) {
//             A.push_back(1);
//         } else {
//             if (A[i] != 1) A[i+1]++;
//         }
//     } else {
//         check = false;
//     }
// }
// int main() {
//     int t;
//     cin >> t;
//     while(t--) {
//         cin >> n;
//         check = true;
//         A.resize(0);
//         A.push_back(n);
//         while(check) {
//             xuat();
//             sinh();
//         }
//         cout << endl;
//     }
//     return 0;
// }
#include <iostream>
using namespace std;
int t,n,k,A[100];
bool ok;

void xuat(){
    for (int i = 1; i<= k; i++){
        if (i == 1) cout << "(";
        cout << A[i];
        if (i < k) cout << " ";
        else cout << ") ";
    } 
}
void sinh(){
    int i = k;
    while(i>=1 && A[i] == 1) i--;
    if (i>=1){
        A[i]--;
        int d = k-i+1;
        k = i;
        for (int j= i+1; j<= i+d/A[i]; j++)
            A[j] = A[i];
        k+= d/A[i];
        if (d % A[i]){
            k++;
            A[k] = d%A[i];
        }
    } else ok = true;
}

int main(){
    cin >> t;
    while(t--){
        ok = false;
        cin >> n;
        k = 1;
        A[k] = n;
        while(!ok){
            xuat();
            sinh();
        }
        cout << endl;
    }
    return 0;
}
