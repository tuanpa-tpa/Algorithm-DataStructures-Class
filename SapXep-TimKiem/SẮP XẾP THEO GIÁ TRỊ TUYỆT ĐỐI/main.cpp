#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct Array {
    int key;
    int value;
};
int part(struct Array A[], int low, int high) {
    int pivot = A[high].value;
    int left = low, right = high-1;
    while(true) {
        while(left <= right && A[left].value < pivot) left++;
        while(left <= right && A[right].value > pivot) right--;
        if (left >= right) break;
        swap(A[left],A[right]);
        left++;right--;
    } 
    swap(A[left],A[high]);
    return left;
}

void quickSort(struct Array A[], int low, int high) {
    if (low < high) {
        int index = part(A,low,high);
        quickSort(A,low,index-1);
        quickSort(A,index+1,high);
    }
}

bool cmp(struct Array A,struct Array B) {
    return A.value < B.value;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n,x;
        cin >> n >> x;
        struct Array A[n];
        for (int i = 0; i< n; i++) {
            cin >> A[i].key;
            A[i].value = abs(x - A[i].key);
        }
        // quickSort(A,0,n-1);
        stable_sort(A,A+n,cmp);
        for (int i = 0; i< n; i++) {
            cout << A[i].key << " ";
        }
        cout << endl;
    }
    return 0;
}