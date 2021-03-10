// #include <iostream>
// #include <stack>
// #include <string>
#include <bits/stdc++.h>
using namespace std;
/*
2
a–(b+c) -> từ vị trí mở ngoặc đến đóng ngoặc nếu trước nó là dấu âm thì đổi dấu
=> dùng stack để lưu vị trí mở ngoặc và đóng ngoặc rồi đổi dấu


a-(b-c-(d+e))-f
a-b-c
a-b+c+d+e-f
*/

string res(string s) {
    stack <int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i); // lưu vị trí mở ngoặc
            } else if (s[i] == ')'){ // gặp vị trí đóng ngoặc
                if (!st.empty()) {
                    int top = st.top();st.pop(); // lấy vị trí mở ngoặc gần nhất
                    if (s[top-1] == '+') continue; // trước nó là dấu + thì k đổi dấu
                    if (s[top-1] == '-') {
                        for (int j = top+1; j< i; j++) { // xét từ đầu ngoặc đến cuối ngoặc
                            if (s[j] == '-') {
                                s[j] = '+';
                            } else if (s[j] == '+') {
                                s[j] = '-';
                            }
                        }
                    }
                }
            }
        }
        // cout << s.length() << endl;
        string temp = "";
        for (int i = 0; i< s.length() ;i++) {
            if (s[i] != '(' && s[i] != ')') {
                temp += s[i];
            }
        }
    return temp;
}

int main() {
    int t ;
    cin >> t;
    while(t--) {
        string s1,s2;
        cin >> s1 >> s2;
        s1 = res(s1);
        s2 = res(s2);
        if (s1 == s2) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}