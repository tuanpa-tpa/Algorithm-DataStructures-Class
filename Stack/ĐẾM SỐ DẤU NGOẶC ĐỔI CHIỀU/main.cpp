#include <iostream>
#include <stack>
using namespace std;
/*
4
))(( 
((((
(((())

)(())((( ->  đếm xem trong chuỗi còn bao nhiêu ngoặc không đúng rồi chỉnh ngoặc không đúng đấy
=> )((( -> có 4 ngặc k đúng => cần đổi thành ()() tại các vị trí 1 2 4 => 3 lần 
tương ứng số ngặc (/2 + )/2 + dư của 2 ngoặc
2
2
1
3
*/
int main() {
    int t;
    cin >> t;
    // t = 1;
    while(t--) {
        string s;
        cin >> s;
        // s = "))((";
        stack <char> st;
        for (int i = 0; i< s.size(); i++) {
            if (s[i] == '(' || (s[i] == ')' && st.empty())) { // xét trường hợp stack rỗng
                st.push(s[i]);
            } else if (s[i] == ')') {
                if (st.top() == '(' && !st.empty()) {
                    st.pop(); // xóa các đấu ngoặc đúng
                } else {
                    st.push(s[i]);
                }
            } 
        }
        int n1=0,n2=0;
        while(!st.empty()) {
            if (st.top() == '(') n1++;
            else n2++;
            st.pop();
        }
        cout << n1/2 + n2/2+ n1%2 + n2%2 << endl;
    }
    return 0;
}