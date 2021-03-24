#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector< vector<int> > list(n+5);
    for (int i = 1; i <= n; i++) {
        string s,token;
        getline(cin >> ws, s); // nhập danh sách các đỉnh kề với đỉnh i
        stringstream ss(s); // dùng để tách các đỉnh
        while(ss >> token) {
            // cout << token << endl;
            int digit = 0;
            for (int i = 0; i < token.size(); i++) {
                digit = digit*10 + int(token[i]-'0'); // chuyển đỉnh thành số
            }
            list[i].push_back(digit); // đỉnh i kề với các đỉnh vừa tách
        }
    }
    // sort(list.begin()+1,list.end()-4);
    // for (int i = 1; i <= n; i++) {
    //     sort(list[i].begin(),list[i].end());
    // }
    bool check_repeat[100][100] = {false}; // làm biến đánh dấu để tránh lặp lại cạnh
    for (int i = 1; i <= n; i++) {
        for (int j = 0 ; j< list[i].size(); j++) {
            if (!check_repeat[i][list[i][j]] && !check_repeat[list[i][j]][i]) { // VD 1-2 thì 2-1 không in nữa
                cout << i << " " << list[i][j] << endl; // đỉnh i và đỉnh kề với nó tạo thành 1 cạnh
                check_repeat[i][list[i][j]] = true;
                check_repeat[list[i][j]][i] = true;
            }
        }
        cout << endl;
    }
    return 0;
}