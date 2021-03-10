#include <iostream>
#include <stack>
using namespace std;
/*
3
((a+b)) ->  thêm vào stack lần lượt, nếu gặp dấu ")" thì tìm dấu "(" gần nó nhất
pop ra
=> nếu trong () mà rỗng thì in ra YES else NO
(a + (b)/c)
(a + b*(c-d))
Yes
Yes
No
*/

bool checkOperator(char x) {
    switch (x){
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
    while(t--) {
        string s;
        getline(cin>>ws, s);
        stack <char> st;
        bool check;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ')') {
                st.push(s[i]);
            } else { // xử lý trường hợp đóng ngoặc
                char top = st.top();st.pop(); // lấy phần từ đầu stack
                check = false; // tạo biến kiểm tra xem trong () có operator hay không
                while (top != '(') { // bỏ cho đến khi đầu stack là "("
                    if (checkOperator(top)) {
                        check = true;
                    }
                    top = st.top();st.pop();
                }
                if (!check) break;
            }
        }
        if (!check) cout << "Yes";
        else cout << "No";
        cout << endl;
    }
    return 0;
}