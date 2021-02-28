#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
3
1 123
2 279134399742
3 987
output
1 132
2 279134423799
3 BIGGEST
*/


string s;
void sinh() {
    int i = s.length()-2;
    while (s[i] >= s[i+1] ) {
        i--;
    }
    if (i >= 0){
        int j = s.length()-1;
        while(s[i] >= s[j]) j--;
        swap(s[i],s[j]);
        int d = i+1, c = s.length()-1;
        while( d < c) {
            swap(s[d],s[c]);
            d++;
            c--;
        }
    }
    else {
        s = "BIGGEST";
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string t;
        cin >> t >> s;
        sinh();
        cout << t << " " << s << endl;
    }
    return 0;
}