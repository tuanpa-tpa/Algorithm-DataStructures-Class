#include <iostream>
#include <string>
using namespace std;

int sumMax(string s1, string s2){
    int n1 = 0,n2 = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '5') s1[i] = '6';
        if (s2[i] == '5') s2[i] = '6';
        n1 = n1*10 + int(s1[i] - '0');
        n2 = n2*10 + int(s2[i] - '0');
    }
    return n1+n2;
}
int sumMin(string s1, string s2) {
    int n1 = 0,n2 = 0;
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == '6') s1[i] = '5';
        if (s2[i] == '6') s2[i] = '5';
        n1 = n1*10 + int(s1[i] - '0');
        n2 = n2*10 + int(s2[i] - '0');
    }
    return n1+n2;
}

int main() {
    // int t;
    // cin >> t;
    // while(t--) {
        string s1 ,s2;
        cin >> s1 >> s2;
        while (s1.size() < s1.size()) s1 = "0" +s1; // cân bằng độ dài 2 số 
        while (s1.size() > s1.size()) s2 = "0" +s2; // để tý chạy 1 for duyệt từng chữ số
        cout << sumMin(s1,s2) << " ";
        cout << sumMax(s1,s2) << endl; 
    // }
    return 0;
}