#include <iostream>
#include <stack>
#include <string>
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
        string s ="*+AB-CD";
        cin >> s;
        stack <string> st;
        for (int i = s.size()-1; i >= 0; i--) {
            if (checkOperator(s[i])) {
                string s1 = st.top();st.pop();
                string s2 = st.top();st.pop();
                string s3 = s1 + s2 + s[i];
                st.push(s3);
            } else {
                st.push(string(1,s[i]));
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}