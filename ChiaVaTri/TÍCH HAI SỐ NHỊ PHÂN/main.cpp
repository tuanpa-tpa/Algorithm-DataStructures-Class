#include <bits/stdc++.h>
using namespace std;

long long POW(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long temp = POW(a,b/2);
    if (b%2==0) return temp*temp;
    return temp*temp*a;
}

long long thapPhan(string s) {
    long long res = 0;
    int d = 0;
    for (int i = s.size()-1; i>=0; i--) {
        if (s[i] == '0') {
            d++;
            continue;
        } else {
            res += POW(2,d);
            d++;
        }
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s1,s2;
        cin >> s1 >> s2;
        long long num1 = thapPhan(s1);
        long long num2 = thapPhan(s2);
        cout << num1*num2 << endl; 
    }
    return 0;
}