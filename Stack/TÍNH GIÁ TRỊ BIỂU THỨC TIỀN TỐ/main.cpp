#include <iostream>
#include <stack>
using namespace std;

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
        string s = "-+8/632";
        cin >> s;
        stack <int> st;
        for (int i = s.size()-1; i >=0; i--) {
            if (checkOperator(s[i])) {
                int s1 = st.top();st.pop();
                int s2 = st.top();st.pop();
                int s3;
                if (s[i] == '*') {
                    s3 = s1*s2;
                } else if (s[i] == '/') {
                    s3 = s1/s2;
                } else if (s[i] == '+') {
                    s3 = s1+s2;
                } else if (s[i] == '-') {
                    s3 = s1-s2;
                }
                st.push(s3);
            } else {
                int temp = int(s[i] -'0');
                st.push(temp);
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}