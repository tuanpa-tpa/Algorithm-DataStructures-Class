#include <iostream>
using namespace std;
string s;

void sinh() {
    int i = s.length()-1;
    while (s[i] == '1') {
        s[i--] = '0';
    }
    if (i >= 0) s[i] ='1';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        sinh();
        cout << s << endl;
    }
    return 0;
}