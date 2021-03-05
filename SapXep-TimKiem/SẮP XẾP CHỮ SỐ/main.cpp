#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<int> s; // dùng set -> do mỗi phần tử trong set là duy nhất và set tự sắp xếp
        set<int> :: iterator it;
        for (int i = 0; i< n; i++) {
            long long temp;
            cin >> temp;
            while(temp){
                int num = temp%10;
                s.insert(num);
                temp/=10;
            }
        }
        for (it = s.begin(); it != s.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
    return 0;
}