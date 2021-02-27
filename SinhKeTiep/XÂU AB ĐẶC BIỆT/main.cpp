#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
string s;
vector <string> A;
bool check = true;
/*
AAABA
AAABB
ABAAA
BAAAB
BBAAA
*/
bool checkA() {
    int B[200] = {0};
    int MAX = 0;
    for (int i = 0; i< n; i++) {
        if (s[i] == 'A') {
            B['A']++;
        } else {
            B['A'] = 0;
        }
        MAX = max(MAX, B['A']);
        if (MAX > k) return false;
    }
    return MAX == k;
}
void sinh() {
    int i = n-1;
    while (s[i] == 'B') {
        s[i--] = 'A';
    }
    if (i >= 0) {
        s[i] = 'B';
    } else {
        check = false;
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        s += "A";
    }    
    check = true;
    while (check) {
        if (checkA()) A.push_back(s);
        // cout << s << endl;
        sinh();
    }
    cout << A.size() << endl;
    for (int i = 0; i< A.size(); i++) {
        cout << A[i] << endl;
    }
    return 0;
}