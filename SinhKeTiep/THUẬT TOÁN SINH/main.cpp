#include <iostream>
#include <vector>
using namespace std;

int k,n;
int A[100];
bool check;
vector < vector<int> > res;

void sinh() {
    int i = n;
    while(A[i] == 1) {
        A[i--] = 0;
    }
    if (i >= 1) {
        A[i] = 1;
    } else {
        check = false;
    }
}

bool checkDX() {
    int i = 1,j = n;
    while(A[i] == A[j]) {
        i++;
        j--;
        if (i >= j) return true;
    }
    return false;
}

void print() {
    // cout << res.size() << endl;
    for (int i = 0; i< res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    check = true;
    cin >> n;
    for (int i = 1; i<= n; i++) {
        A[i] = 0;
    }
    while(check) {
        if (checkDX()) {
            vector <int> req;
            for (int i = 1; i<= n; i++) {
                req.push_back(A[i]);
            }
            res.push_back(req);
        }
        sinh();
    }
    print();
    return 0;
}