/*
2
2 3
1 3
1/2 + 1/6 
1/3
=>  phân tích thành dạng 1/x
nêu x là số nguyên thì dừng còn không thì + 1 và lấy phần nguyên
1/(3/2) -> 1/[(3/2)+1] = 1/2    +  x/y
x/y = 2/3 - 1/2
x = 2*2-3 = 1 -> tử ban đầu nhân với mẫu sau trừ đi mẫu trước
y = 2 * 3 = 6 -> mẫu ban đầu nhân với mẫu sau
x/y = 1/6
*/

#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        long long tu,mau;
        cin >> tu >> mau;
        long long temp; // vì số rất lớn. :< làm WA mấy lần
        while(true) {
            if (mau%tu == 0) {
                cout << "1/" << mau/tu << endl;
                break;
            }
            temp = mau/tu + 1;
            cout << "1/" << temp << " + ";
            tu = tu*temp - mau;
            mau = mau*temp;
        }
    }
    return 0;
}