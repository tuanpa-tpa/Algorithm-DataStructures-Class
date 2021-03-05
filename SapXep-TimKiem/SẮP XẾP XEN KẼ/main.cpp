#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int part(vector <int> &A, int low, int high) {
    int pivot = A[high];
    int left = low, right = high - 1;
    while(true) {
        while(A[left] < pivot && left <= right)  left++;
        while(A[right] > pivot && left <= right)  right--;
        if (left >= right) break;
        swap(A[left],A[right]);
        left++;right--;
    }
    swap(A[left],A[high]);
    return left;
}


void quickSort(vector<int> &A, int low, int high) {
    if (low < high) {
        int index = part(A,low,high);
        quickSort(A,low,index-1);
        quickSort(A,index+1,high);
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> A(1005);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        quickSort(A,0,n-1);
        int left = 0, right = n-1;
        while(left <= right) {
            if (left == right) cout << A[right];
            else
            cout << A[right] << " " << A[left] << " ";
            right--;left++;
        }
        cout << endl;
    }
    return 0;
}
