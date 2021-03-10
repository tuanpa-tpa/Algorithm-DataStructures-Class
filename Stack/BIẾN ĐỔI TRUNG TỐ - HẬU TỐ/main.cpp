#include <iostream>
#include <stack>
using namespace std;
int checkOperator(char c) {
    if (c == '^') 
        return 3; 
    else if (c == '*' || c == '/') 
        return 2; 
    else if (c == '+' || c == '-') 
        return 1; 
    else 
        return -1; 
}

int main() {
    int t;
    cin >> t;
    // t =1;
    while (t--) {
        string s ="((A+B)*C+D)";
        cin >> s;
        stack < char > st;
        string res= "";
        for (int i = 0; i < s.size(); i++) {
            char x = s[i]; 
            if ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
                res = res + x; 
            else if (x == '(') 
                st.push(x); 
            else if (x == ')') { 
                while (!st.empty() && st.top() != '(') { //lặp lại đén khi gặp '('
                    res = res + st.top();
                    st.pop(); 
                }
                st.pop(); //loai '(' ra khoi stack
            } else { // nếu là phép toán -> xét độ ưu tiên của phép toán
                while (!st.empty() && checkOperator(x) <= checkOperator(st.top())) { // độ ưu tiên s[i]>st.top()
                    res = res + st.top(); 
                    st.pop(); 
                }
                st.push(x); //đưa phép toán vào
            }
        }
        //đưa các phép toán còn lại vào
        while (!st.empty()) {
            if (st.top() != '(') {
                res = res + st.top();
            }
            st.pop();
        }
        cout << res << endl;
        }
    return 0;
}
