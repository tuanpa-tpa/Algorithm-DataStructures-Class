#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
bool check = true;
void sinh() {
    int i = s.size()-2;
    while (s[i] > s[i+1]) i--;
    if (i >= 0) {
        int j = s.size()-1;
        while(s[i] > s[j]) j--;
        swap(s[i],s[j]);
        int d = i+1, c = s.size()-1;
        while(d < c) {
            swap(s[d],s[c]);
            d++;c--;
        }
    } else {
        check = false;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> s;
        check = true;
        while (check) {
            cout << s << " ";
            sinh();
        }
        cout << endl;
    }
    return 0;
}