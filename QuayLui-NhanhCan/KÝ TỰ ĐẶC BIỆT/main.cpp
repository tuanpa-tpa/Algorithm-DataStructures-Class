#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long n;
        string s;
        cin >> s >> n;
        long long temp = s.size();
        while(temp < n) temp *= 2;

        while(temp > s.size()) {
            if (n > temp/2) { // nếu nó ở xâu đảo
                n -= temp/2; // quy vị trí về xâu ban đầu 
                if (n == 1) n = temp/2; // nếu ở đầu xâu đảo=> cuối xâu ban đầu
                else n = n-1; // không phải đầu
            }
            temp /= 2; //  chia nhỏ xâu
        }
        cout << s[n-1] << endl;
    }
    return 0;
}