#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map <long long, bool> mp;
long long res = -1;
long long n;
vector <int> req;
int A[50];

void backTrack(int i) {
    for (int j = 0; j <= 1; j++) {
        A[i] = j;
        if (i == (req.size())-1) {
            long long temp = 0;
            for (int k = 0; k < req.size(); k++) {
                if (A[k] == 1) {
                    temp = temp*10 + req[k];
                }
            }
            if (mp[temp] == true && temp != 0 && temp > res) {
                res = temp;
            }
        } else {
            backTrack(i+1);
        }
    }
}

int main() {
    for (long long i = 1 ; i <= 150000; i++) {
        mp[i*i*i] = true; // lưu số lập phương
    }
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        res = -1;
        req.clear();
        while(n) {
            req.push_back(n%10);
            n/=10;
        }
        reverse(req.begin(), req.end());
        backTrack(0);
        cout << res << endl;
    }
    return 0;
}