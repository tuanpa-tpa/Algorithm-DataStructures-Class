#include <iostream>
#include <string>
#include <stack>
using namespace std;
/*
3
((()
0123
)()())
012345
()(()))))
012345678
*/
int longest_string(string s) {
    int res = 0;
    int length_String = s.length();
    stack <int> st;
    st.push(-1);
    for (int i = 0; i < length_String; i++) {
        if (s[i] == '(') { // nếu là ( thì thêm vị trí đấy vào
            st.push(i);
        } else {
            st.pop(); // xóa đi dấu ( trước đó
            if (!st.empty()){ // kiểm tra nếu stack rỗng thì thiết lập lại vị trí ban đầu
                res = max(res, i - st.top()); // tìm max
            } else {
                st.push(i);
            }
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;   
        // s = ")()())";
        cout << longest_string(s) << endl;
    }
    return 0;
}