#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
2
*+AB-CD
*-A/BC-/AKL
((A+B)*(C-D))
((A-(B/C))*((A/K)-L)
=> duyệt từ phải qua trái, gặp operator thì lấy ra 2 phần từ đầu stack 
gọi là s1 và s2
khi đấy res = (+s1+operator+s2+) -> push vào stack tiếp
*/

bool checkOperator(char x) {
    switch(x) {
        case '+':
            return true;
        case '-':
            return true;
        case '*':
            return true;
        case '/':
            return true;
        default:
            return false;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    // t = 1;
    while(t--) {
        string s ="*+AB-CD";
        cin >> s;
        stack <string> st;
        for (int i = s.size()-1; i>= 0; i--) {
            if (checkOperator(s[i])) {
                string s1 = st.top();st.pop();
                string s2 = st.top();st.pop();
                string s3 = "(" + s1 + s[i] + s2 + ")";
                st.push(s3);
            } else {
                st.push(string(1,s[i]));
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}