#include <iostream>
#include <vector>
using namespace std;

string A[105];

string add(string s1, string s2) {
    // cân bằng 2 chuỗi
    while(s1.size() < s2.size()) s1 = "0" + s1;
    while(s1.size() > s2.size()) s2 = "0" + s2;
    string res = "";
    int length1 = s1.size();
    int modu = 0;
    // cout << s1 << endl << s2 << endl;
    for (int i = length1 - 1; i >= 0 ; i--) {
        int temp = int(s1[i] - '0') + int(s2[i] - '0') + modu;
        modu = temp / 10;
        temp %= 10;
        res = char(temp + '0') + res;
    }
    if (modu) {
        res = char(modu + '0') + res;
    }
    return res;
}

string mul(string s1, string s2) {
    string res = "";
    int n1 = 0, modu = 0;
    int length1 = s1.size();
    int length2 = s2.size();
    if (length1 == 0 || length2 == 0) return "0";
    vector <int> B(length1 + length2, 0);
    for (int i = length1 - 1 ; i >= 0 ; i--) {
        int num1 = int(s1[i] - '0');
        int n2 = 0;
        modu = 0; // gán dư ban đầu bằng 0
        for (int j = length2 - 1; j >= 0; j--) {
            int num2 = int(s2[j] - '0');
            int num = num1*num2 + B[n1+n2] + modu;
            modu = num/10;
            num %= 10;
            B[n1+n2] = num;
            n2++;
        }
        if (modu) {
            B[n1+n2] += modu;
        }
        n1++;
    }
    int i = B.size() - 1;
    while(B[i] == 0 && i >= 0) i--;
    while(i >= 0) {
        res += char(B[i--] + '0');
    }
    return res;
}

void response() {
    A[0] = "1";
    A[1] = "1";
    for (int i = 2; i <= 100; i++) {
        A[i] = "0";
        for (int j = 0; j < i; j++) {
            A[i] = add(A[i], mul(A[j], A[i - j - 1])) ;
        }
    }
}

int main() {
    response();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << A[n];
        cout << endl;
    }
    return 0;
}