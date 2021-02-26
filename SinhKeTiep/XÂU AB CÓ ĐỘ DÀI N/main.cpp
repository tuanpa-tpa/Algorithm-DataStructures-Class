#include <iostream>
#include <string>
using namespace std;

string s;
bool check;
void sinh() {
    int i = s.length()-1;
    while(s[i] == 'B') {
        s[i--] = 'A';
    }
    if (i >= 0) {
        s[i] = 'B';
    } else {
        check = false;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        s = "";
        for (int i = 0; i< n; i++) {
            s += "A";
        }
        check = true;
        while(check) {
            // for (int i = 0; i< n; i++) {
            //     s[i] = 'A';
            // }   
            cout << s << " ";
            sinh();
        }
        cout << endl;
    }
    return 0;
}