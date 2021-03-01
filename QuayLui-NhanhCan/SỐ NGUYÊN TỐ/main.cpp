#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199}; 
bool B[205] = {false};
int n,p,s;
vector < vector<int> > res;
vector <int> req;
/*

*/


void sangNT() { // dùng sàng để lưu các số nt vô mảng A
    for (int i = 2; i<= 200; i++) {
        if (!B[i])
        for (int j = i*2; j <= 200; j+=i) {
            B[j] = true;
        }
    }
    for (int i = 2; i<= 200; i++) {
        if (!B[i]) {
            cout << i <<", ";
        }
    }
}

void backTrack(int i, int sum) {
    if (sum > s) return; // nếu tổng mà lớn hơn s thì bỏ
    if ((sum == s) && (req.size() == n)) {
        res.push_back(req);
        return;
    }
    for (int j = i; j <= 46; j++) { // trong mảng A có 46 số
        if (!B[j] && (sum + A[j] <= s) && (req.size() < n)){ 
            // chỉ thêm vô req khi cộng số đó mà tổng vẫn nhỏ hơn s 
            //số đấy chưa được chọn
            // số lượng phần tử nhỏ hơn n
            req.push_back(A[j]);
            B[j] = true;
            backTrack(j+1, sum + A[j]); // j+1 để không bị hoán vị các giá trị
            /*
                3 7 13 
                3 13 7 
                5 7 11 
                5 11 7 
                7 5 11 
                11 5 7 
            */
            req.pop_back();
            B[j] = false;
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> p >> s;
        int index = 0;
        while(A[index] <= p) index++;
        req.clear(); // xóa phần tử cũ
        res.clear();
        for (int i = 0; i < 205; i++) B[i] = false;
        backTrack(index,0);
        sort(res.begin(),res.end());
        cout << res.size() << endl;
        for (int i = 0; i< res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}