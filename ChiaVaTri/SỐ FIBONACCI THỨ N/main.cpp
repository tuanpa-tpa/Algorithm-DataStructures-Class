#include <iostream>
using namespace std;
struct Matran{
    long long M[3][3];
};
const long long M = 1e9+7;
Matran operator *(Matran A, Matran B){
    Matran C;
    for (int i = 1; i<= 2; i++){
        for (int j = 1; j<= 2; j++){
            C.M[i][j] = 0;
            for (int k = 1; k<= 2; k++){
                C.M[i][j] = (C.M[i][j] + (A.M[i][k]*B.M[k][j])%M)%M;
            }
        }
    }
    return C;
}
Matran luythua(Matran A,long long k){
    if ( k == 1) return A;
    Matran B = luythua(A,k/2);
    if (k % 2 == 0) return B*B;
    else return A*B*B;
}

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        Matran A;
        A.M[1][1] = 1;A.M[1][2] = 1;
        A.M[2][1] = 1;A.M[2][2] = 0;
        Matran kq = luythua(A,n-1);
        cout << kq.M[1][1];
        cout << endl;
    }
    return 0;
}