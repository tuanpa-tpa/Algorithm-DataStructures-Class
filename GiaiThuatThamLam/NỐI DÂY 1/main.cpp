#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        priority_queue <long long, vector<long long> , greater<long long> > pq;
        for (int i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            pq.push(temp);
        }
        long long res = 0;
        while(pq.size() > 1) {
            long long num1 = pq.top(); pq.pop();
            long long num2 = pq.top(); pq.pop();
            long long sum = num1+num2;
            res += sum;
            pq.push(sum);
        }
        cout << res << endl;
    }
    return 0;
}